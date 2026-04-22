#include "GameScene.h"
#include "GameContext.h"
#include "assetManager.h"
#include "entityFactory.h"
#include "player.h"
#include <memory>

GameScene::GameScene(GameContext &ctx) : am(), factory(am) {
  player = factory.createEntity<Player>("player", ctx.width / 2.0,
                                        ctx.height / 2.0, ctx.renderer);

  if (!player) {
    std::cerr << "ERROR: Player was not created by factory!" << std::endl;
  }
}

void GameScene::handleEvent(GameContext &ctx, const SDL_Event &event) {}

void GameScene::update(GameContext &ctx, float deltaTime) {
  player->update(deltaTime, ctx);
}

void GameScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);

  player->draw(ctx.renderer);
}
