#include "final_scene.h"
#include "GameContext.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "score_manager.h"
#include <SDL3_image/SDL_image.h>
#include <format>

FinalScene::FinalScene(GameContext &ctx) {
  message = IMG_LoadTexture(ctx.renderer, "../assets/final.png");

  engine = TTF_CreateRendererTextEngine(ctx.renderer);

  font = TTF_OpenFont("../assets/Roboto.ttf", 42);

  int score = ScoreManager::getInstance().getScore();
  scoreText = TTF_CreateText(engine, font, "", 0);
  if (scoreText) {
    std::string strScores = std::format("Очки: {}/100", score);

    TTF_SetTextString(scoreText, strScores.c_str(), 0);
    TTF_SetTextColor(scoreText, 0, 0, 0, 255);

    int textW = 0;
    int textH = 0;
    TTF_GetTextSize(scoreText, &textW, &textH);

    textX = (ctx.width - static_cast<float>(textW)) / 2.0f;
    const float thirdHeight = ctx.height / 3.0f;
    textY =
        (thirdHeight * 2.0f) + (thirdHeight - static_cast<float>(textH)) / 2.0f;
  }

  float texW = 0, texH = 0;
  SDL_GetTextureSize(message, &texW, &texH);

  messageRect = {(ctx.width - texW) / 2.0f, (ctx.height - texH) / 2.0f, texW,
                 texH};
}

void FinalScene::handleEvent(GameContext &ctx, const SDL_Event &event) {
  if (event.type == SDL_EVENT_SCORE_CHANGED) {
  }
}

void FinalScene::update(GameContext &ctx, float DeltaTime) {}

void FinalScene::render(GameContext &ctx) const {
  SDL_SetRenderDrawColor(ctx.renderer, 255, 255, 190, 255);
  SDL_RenderClear(ctx.renderer);

  if (scoreText) {
    TTF_DrawRendererText(scoreText, textX, textY);
  }

  SDL_RenderTexture(ctx.renderer, message, NULL, &messageRect);
}

FinalScene::~FinalScene() {
  TTF_DestroyText(scoreText);
  TTF_CloseFont(font);
  TTF_DestroyRendererTextEngine(engine);
  SDL_DestroyTexture(message);
}
