#include "win_scene.h"
#include "GameContext.h"
#include "SDL3/SDL_render.h"

WinScene::WinScene(const GameContext &ctx) : am() {
  message = am.getTexture("../assets/win.png", ctx.renderer);

  float msgW, msgH;
  SDL_GetTextureSize(message, &msgW, &msgH);

  meessgeRect = {(ctx.width - msgW) / 2.0f, (ctx.height - msgH) / 2.0f, msgW,
                 msgH};
}

void WinScene::handleEvent(GameContext &ctx, const SDL_Event &event) {}

void WinScene::update(GameContext &ctx, float deltaTime) {}

void WinScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);

  SDL_RenderTexture(ctx.renderer, message, NULL, &meessgeRect);
}

WinScene::~WinScene() { SDL_DestroyTexture(message); }
