#include "entity.h"
#include "GameContext.h"
#include <SDL3/SDL.h>
#include <string>

Entity::Entity(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : asset(tex), transform({x, y, 0.0f, 0.0f}), maxHp(config.hp),
      speed(config.speed) {
  hp = maxHp;
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
    this->hp = 0;
    this->deactivate();
  }
}

void Entity::activate() {
  hp = maxHp;
  this->active = true;
}

void Entity::update(float dt, const GameContext &ctx) {}

const float Entity::getHP() const { return this->hp; }

std::string Entity::getType() const { return this->type; }
