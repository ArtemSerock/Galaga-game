#include "Game.h"
#include "SDL3/SDL_init.h"
#include <iostream>

Game::Game() {}
SDL_AppResult Game::Init(std::string_view title, int width, int height) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer(title.data(), width, height, 0, &ctx.window,
                                   &ctx.renderer)) {
    std::cerr << "Failed to create Window/Renderer: " << SDL_GetError()
              << std::endl;
    return SDL_APP_FAILURE;
  }

  return SDL_APP_CONTINUE;
}

SDL_AppResult Game::HandleEvents(SDL_Event *event) {
  if (event->type == SDL_EVENT_QUIT) {
    return SDL_APP_SUCCESS;
  }
  return SDL_APP_CONTINUE;
}

void Game::Update() {
  // Здесь будет логика перемещения объектов, проверки столкновений и т.д.
}

void Game::Render() {
  // Устанавливаем цвет фона (например, черный)
  SDL_SetRenderDrawColor(ctx.renderer, 0, 0, 0, 255);
  SDL_RenderClear(ctx.renderer);

  // Здесь вызываются функции отрисовки объектов

  // Выводим результат на экран
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
