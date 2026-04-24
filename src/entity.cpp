#include "entity.h"
#include <SDL3/SDL.h>
#include <iostream>

Entity::Entity(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : asset(tex), transform({x, y, 0.0f, 0.0f}), hp(config.hp),
      speed(config.speed) {
  transform.w = config.width;
  transform.h = config.height;
}

void Entity::draw(SDL_Renderer *renderer) const {
  if (asset && this->active) {
    SDL_RenderTexture(renderer, asset, NULL, &this->transform);
  }
}

bool Entity::isActive() const { return this->active; }

void Entity::deactivate() { this->active = false; }

const SDL_FRect &Entity::getRect() const { return this->transform; }

void Entity::takeDamage(float amount) {
  this->hp -= amount;

  if (this->hp <= 0) {
    this->deactivate();
  }
}

void Entity::activate() { this->active = true; }
