#include "Game.h"
#include <iostream>

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
