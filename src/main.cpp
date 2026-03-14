#include "Game.h"
#include "GameContext.h"
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

GameContext ctx;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    auto game = std::make_unique<Game>();
    
    SDL_AppResult result = game->Init("GALAGA", 800, 600);
    
    if (result == SDL_APP_CONTINUE) {
        *appstate = game.release();
    }
    
    return result;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    auto* game = static_cast<Game*>(appstate);
    game->Update();
    game->Render();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event){
  auto* game = static_cast<Game*>(appstate);
  game->HandleEvents();
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
  std::unique_ptr<Game> game(static_cast<Game*>(appstate));
}
