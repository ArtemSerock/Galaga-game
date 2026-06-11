#include "GameScene.h"
#include "GameContext.h"
#include "assetManager.h"
#include "entityFactory.h"
#include "player.h"
#include "score_manager.h"
#include <memory>

GameScene::GameScene(GameContext &ctx) : am(), factory(am) {
  player = factory.createEntity<Player>(
      "player", ctx.width / 2.0f, (ctx.height / 3.0f) * 2.0f, ctx.renderer);

  cm = std::make_unique<CollisionManager>(*player, player_bullets);

  pause = IMG_LoadTexture(ctx.renderer, "../assets/pause.png");
  float textureW = 0, textureH = 0;
  SDL_GetTextureSize(pause, &textureW, &textureH);

  pauseRect = {(ctx.width - textureW) / 2.0f, 0.0f, textureW, textureH};
  if (!player) {
    std::cerr << "ERROR: Player was not created by factory!" << std::endl;
  }
}

void GameScene::handleEvent(GameContext &ctx, const SDL_Event &event) {
  if (!player->isActive()) {
    ctx.nextScene = SceneType::GAME_OVER;
  }

  if (event.type == SDL_EVENT_KEY_UP) {
    if (event.key.key == SDLK_ESCAPE)
      isPause = !isPause;
  }
}

void GameScene::update(GameContext &ctx, float deltaTime) {
  if (!isPause) {
    player->update(deltaTime, ctx, player_bullets, factory);
    player_bullets.update(deltaTime, ctx);
    bees.update(deltaTime, ctx);

    if (this->beeTimer > 0.0f) {
      this->beeTimer -= deltaTime;
    }

    if (this->beeTimer <= 0) {
      this->bees.spawn(factory, ctx, player->getRect().x, player->getRect().y);
      this->beeTimer = beeCooldown;
    }

    bool isEnemyDestroy =
        cm->CheckCollisionEnemyAndBullet<Bee, 20>(bees.getPool());
    if (isEnemyDestroy) {
      ScoreManager::getInstance().addScore(1);
    }

    bool isPlayerHit =
        cm->CheckCollisionPlayerAndEnemy<Bee, 20>(bees.getPool());
    if (isPlayerHit) {
      shakeTime = 0.4f;
      shakeForce = 10.0f;
    }

    if (shakeTime > 0.0f) {
      shakeTime -= deltaTime;

      if (shakeTime <= 0.0f) {
        shakeTime = 0.0;
        shakeForce = 0.0f;
      }
    }
  }
}

void GameScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);

  if (shakeTime > 0.0f) {
    int dx = (rand() % ((int)shakeForce * 2 + 1)) - (int)shakeForce;
    int dy = (rand() % ((int)shakeForce * 2 + 1)) - (int)shakeForce;

    SDL_Rect viewport = {dx, dy, ctx.width, ctx.height};
    SDL_SetRenderViewport(ctx.renderer, &viewport);
  }

  player_bullets.draw(ctx.renderer);
  bees.draw(ctx.renderer);

  player->draw(ctx.renderer);
  if (shakeTime > 0.0f) {
    SDL_SetRenderViewport(ctx.renderer, nullptr);
  }

  if (isPause) {
    SDL_RenderTexture(ctx.renderer, pause, NULL, &pauseRect);
  }
}

GameScene::~GameScene() { SDL_DestroyTexture(pause); }
