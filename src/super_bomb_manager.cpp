#include "super_bomb_manager.h"
#include "configManager.h"
#include "super_bomb.h"

const Uint32 SDL_EVENT_SUPER_BOMB_USED = SDL_RegisterEvents(1);

SuperBombManager &SuperBombManager::getInstance() {
  static SuperBombManager instance;
  return instance;
}

void SuperBombManager::pushUpdateEvent() {
  if (SDL_EVENT_SUPER_BOMB_USED != (Uint32)-1) {
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_EVENT_SUPER_BOMB_USED;
    event.user.code = this->count;
    SDL_PushEvent(&event);
  }
}

int SuperBombManager::getCount() const { return this->count; }

void SuperBombManager::init(SDL_Texture *asset) {
  const auto data = ConfigManager::get("constants");
  const int radius = data.value("super_bomb_radius", 100);
  count = data.value("super_bomb_count", 1);
  cooldown_duration = data.value("super_bomb_duration", 0.0f);
  cooldown_timer = cooldown_duration;
  bomb = SuperBomb(asset, radius, 2.0f);
}

void SuperBombManager::draw(SDL_Renderer *renderer) { bomb.draw(renderer); }

void SuperBombManager::update(float dt) {
  bomb.update(dt);
  if (cooldown_timer > 0.0f) {
    cooldown_timer -= dt;
  }
}

void SuperBombManager::boom(float x, float y) {
  if (cooldown_timer <= 0) {
    bomb.spawn(x, y);
    cooldown_timer = cooldown_duration;
  }
}
