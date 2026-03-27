#include "GameScene.h"
#include "GameContext.h"

void GameScene::handleEvent(GameContext &ctx, const SDL_Event &event) {
  // Здесь будет управление кораблем
}

void GameScene::update(GameContext &ctx, float deltaTime) {
  // Здесь будет движение врагов
}

void GameScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);
}
