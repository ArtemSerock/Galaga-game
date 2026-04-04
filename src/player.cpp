#include "player.h"
#include "entity.h"
#include "physic.h"
#include <array>
#include <SDL3/SDL.h>

Player::Player(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : Entity(tex, x, y, config) {}

void Player::update(float dt) {
  const bool *keys = SDL_GetKeyboardState(NULL);

  const float speed_per_second = speed * dt;

  std::array<float, 2> direction  = {0.0f, 0.0f};
  
  if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT])  direction[0] -= 1.0f;
  if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) direction[0] += 1.0f;
  if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP])    direction[1] -= 1.0f;
  if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN])  direction[1] += 1.0f;

  float length = Physic::length2D(direction);
  if (length > 0.0f){
    Physic::normalize2D(direction);
  }
  


  this->transform.x += direction[0] * speed_per_second;
  this->transform.y += direction[1] * speed_per_second;
}


Player::~Player(){
  SDL_DestroyTexture(this->asset);
}