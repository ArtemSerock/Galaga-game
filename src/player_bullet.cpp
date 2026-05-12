#include "player_bullet.h"
#include "GameContext.h"
#include "particle.h"
#include "particleConfig.h"
#include <SDL3/SDL.h>

PlayerBullet::PlayerBullet(SDL_Texture *tex, float x, float y,
                           const ParticleConfig &config)
    : Particle(tex, x, y, config) {}

void PlayerBullet::update(float dt, const GameContext &ctx) {
  const float vel_x_per_second = this->velocity_x * dt;
  const float vel_y_per_second = this->velocity_y * dt;

  this->transform.x += vel_x_per_second;
  this->transform.y += vel_y_per_second;

  if (this->transform.y + this->transform.h < 0) {
    this->deactivate();
  }
}
