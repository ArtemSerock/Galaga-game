#include "super_bomb_manager.h"

int SuperBombManager::getCount() const { return this->count; }

void SuperBombManager::SubCount(int value = 1) {
  this->count -= value;
  pushUpdateEvent();
}

void SuperBombManager::pushUpdateEvent() {
  if (SDL_EVENT_SUPER_BOMP_USED != (Uint32)-1) {
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_EVENT_SUPER_BOMP_USED;
    event.user.code = this->count;
    SDL_PushEvent(&event);
  }
}

void SuperBombManager::init(int start_count) { this->count = start_count; }
