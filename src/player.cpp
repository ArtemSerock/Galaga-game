#include "player.h"
#include "entity.h"
#include <SDL3/SDL.h>

Player::Player(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : Entity(tex, x, y, config) {}

void Player::update(float dt) {
  const bool *keys = SDL_GetKeyboardState(NULL);

  if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) {
    this->transform.x -= speed * dt;

  } else if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) {
    this->transform.x += speed * dt;
  }
}


Player::~Player(){
  SDL_DestroyTexture(this->asset);
}