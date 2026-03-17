#include "MenuScene.h"
#include "GameContext.h"
#include "SDL3/SDL_keycode.h"

void MenuScene::handleEvent(GameContext &ctx, const SDL_Event &event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        if (event.key.scancode == SDL_SCANCODE_RETURN || 
            event.key.scancode == SDL_SCANCODE_KP_ENTER) {
            ctx.nextScene = SceneType::GAME;
        }
    }
}


void MenuScene::update(GameContext &ctx, float deltaTime) {
  // TODO
}

void MenuScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 0, 0, 255);
  SDL_RenderClear(ctx.renderer);
}
