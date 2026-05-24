#include "final_scene.h"
#include "GameContext.h"
#include "SDL3/SDL_render.h"
#include <SDL3_image/SDL_image.h>

FinalScene::FinalScene(GameContext &ctx) {
  message = IMG_LoadTexture(ctx.renderer, "../assets/final.png");
  float texW = 0, texH = 0;
  SDL_GetTextureSize(message, &texW, &texH);

  messageRect = {(ctx.width - texW) / 2.0f, (ctx.height - texH) / 2.0f, texW,
                 texH};
}

void FinalScene::handleEvent(GameContext &ctx, const SDL_Event &event) {}

void FinalScene::update(GameContext &ctx, float DeltaTime) {}

void FinalScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);
  SDL_RenderTexture(ctx.renderer, message, NULL, &messageRect);
}

FinalScene::~FinalScene() { SDL_DestroyTexture(message); }
