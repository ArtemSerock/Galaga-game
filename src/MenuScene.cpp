#include "MenuScene.h"
#include "GameContext.h"
#include <SDL3_image/SDL_image.h>

MenuScene::MenuScene(GameContext &ctx) : am() {
  logo = am.getTexture("../assets/logo.png", ctx.renderer);
  label = am.getTexture("../assets/press_space.png", ctx.renderer);
  control = am.getTexture("../assets/control.png", ctx.renderer);

  float texW = 0, texH = 0;
  SDL_GetTextureSize(logo, &texW, &texH);

  float labelW = 0, labelH = 0;
  SDL_GetTextureSize(label, &labelW, &labelH);

  float controlW = 0, controlH = 0;
  SDL_GetTextureSize(control, &controlW, &controlH);

  logoRect = {(ctx.width - texW) / 2.0f, (ctx.height - texH) / 2.0f, texW,
              texH};

  labelRect = {(ctx.width - labelW) / 2.0f, (ctx.height - labelH) / 2.0f + texH,
               labelW, labelH};

  controlRect = {(ctx.width - controlW) / 2.0f, 0, controlW, controlH};
}

void MenuScene::handleEvent(GameContext &ctx, const SDL_Event &event) {
  if (event.type == SDL_EVENT_KEY_DOWN) {
    if (event.key.scancode == SDL_SCANCODE_SPACE) {
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
  SDL_RenderTexture(ctx.renderer, control, NULL, &controlRect);
}

MenuScene::~MenuScene() {
  SDL_DestroyTexture(logo);
  SDL_DestroyTexture(label);
  SDL_DestroyTexture(control);
}
