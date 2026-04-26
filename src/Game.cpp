#include "Game.h"
#include "GameContext.h"
#include <iostream>

Game::Game() {}
SDL_AppResult Game::Init(std::string_view title) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer(title.data(), ctx.width, ctx.height, 0,
                                   &ctx.window, &ctx.renderer)) {
    std::cerr << "Failed to create Window/Renderer: " << SDL_GetError()
              << std::endl;
    return SDL_APP_FAILURE;
  }

  SDL_SetRenderVSync(ctx.renderer, 1);

  lastTicks = SDL_GetTicksNS();
  ctx.nextScene = SceneType::MENU;

  return SDL_APP_CONTINUE;
}

SDL_AppResult Game::HandleEvents(SDL_Event *event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }
  if (ctx.activeScene) {
    ctx.activeScene->handleEvent(ctx, *event);
  }
  return SDL_APP_CONTINUE;
}

void Game::Update() {
  ctx.updateScene();
  uint64_t currentTicks = SDL_GetTicksNS();

  float deltaTime = (float)(currentTicks - lastTicks) / 1000000000.0f;

  lastTicks = currentTicks;

  if (deltaTime > 0.1f)
    deltaTime = 0.016f;

  if (ctx.activeScene) {
    ctx.activeScene->update(ctx, deltaTime);
  }
}

void Game::Render() {

  if (ctx.activeScene) {
    ctx.activeScene->render(ctx);
  }
  SDL_RenderPresent(ctx.renderer);
}

void Game::Clean() {
  if (ctx.renderer) {
    SDL_DestroyRenderer(ctx.renderer);
    ctx.renderer = nullptr;
  }

  if (ctx.window) {
    SDL_DestroyWindow(ctx.window);
    ctx.window = nullptr;
  }

  SDL_Quit();
}

Game::~Game() { Clean(); }
