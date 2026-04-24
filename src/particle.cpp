#include "particle.h"
#include "SDL3/SDL_render.h"
#include <SDL3/SDL.h>

Particle::Particle(SDL_Texture *tex, float x, float y,
                   const ParticleConfig &config)
    : tex(tex), transform({x, y, 0.0f, 0.0f}), velocity_x(config.vel_x),
      velocity_y(config.vel_y) {

  transform.w = config.width;
  transform.h = config.height;
}

Particle::~Particle() { SDL_DestroyTexture(tex); }

void Particle::draw(SDL_Renderer *renderer) const {
  if (tex && this->active) {
    SDL_RenderTexture(renderer, tex, NULL, &this->transform);
  }
}

bool Particle::isActive() const { return this->active; }

void Particle::deactivate() { this->active = false; }

void Particle::activate() { this->active = true; }

const SDL_FRect &Particle::getRect() const { return this->transform; }
