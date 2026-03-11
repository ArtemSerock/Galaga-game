#include "Game.h"
#include <iostream>
#include <string_view>>

bool Game::Init(std::string_view title, int width, int height) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return false;
  }

  if (!SDL_CreateWindowAndRenderer(title.data(), width, height, 0, &ctx.window,
                                   &ctx.renderer)) {
    std::cerr << "Failed to create Window/Renderer: " << SDL_GetError()
              << std::endl;
    return false;
  }
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

  ctx.isRunning = false;
}

Game::~Game() { Clean(); }
