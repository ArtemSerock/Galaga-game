#include "MenuScene.h"
#include "GameContext.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include <SDL3_image/SDL_image.h>

MenuScene::MenuScene(GameContext &ctx) {
  logo = IMG_LoadTexture(ctx.renderer, "../assets/logo.png");
  label = IMG_LoadTexture(ctx.renderer, "../assets/press_enter.png");

  float texW = 0, texH = 0;
  SDL_GetTextureSize(logo, &texW, &texH);

  float labelW = 0, labelH = 0;
  SDL_GetTextureSize(label, &labelW, &labelH);

  logoRect = {(ctx.width - texW) / 2.0f, (ctx.height - texH) / 2.0f, texW,
              texH};

  labelRect = {(ctx.width - labelW) / 2.0f, (ctx.height - labelH) / 2.0f + texH,
               labelW, labelH};
}

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
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);
  SDL_RenderTexture(ctx.renderer, logo, NULL, &logoRect);
  SDL_RenderTexture(ctx.renderer, label, NULL, &labelRect);
  SDL_RenderPresent(ctx.renderer);
}

MenuScene::~MenuScene() {
  SDL_DestroyTexture(logo);
  SDL_DestroyTexture(label);
}
