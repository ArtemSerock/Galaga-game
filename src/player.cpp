#include "player.h"
#include "GameContext.h"
#include "bullet_pool.h"
#include "entity.h"
#include "entityFactory.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <iostream>

Player::Player(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : Entity(tex, x, y, config) {}

void Player::update(float dt, const GameContext &ctx, BulletPool &pool,
                    EntityFactory &factory) {
  const bool *keys = SDL_GetKeyboardState(NULL);

  const float speed_per_second = speed * dt;
  if (shootTimer > 0.0f) {
    shootTimer -= dt;
  }

  float directionX = 0.0f;

  if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT])
    directionX -= 1.0f;
  if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT])
    directionX += 1.0f;

  // 2. Стрельба
  if (keys[SDL_SCANCODE_SPACE] && shootTimer <= 0.0f) {
    this->shoot(pool, factory, ctx);
    std::cout << "SHOOT" << std::endl;
  }

  this->transform.x += directionX * speed_per_second;

  this->transform.x =
      std::max(0.0f, std::min(transform.x, ctx.width - transform.w));
}

void Player::update(float dt, const GameContext &ctx) {
  Entity::update(dt, ctx);
}

Player::~Player() { SDL_DestroyTexture(this->asset); }

void Player::shoot(BulletPool &pool, EntityFactory &factory,
                   const GameContext &ctx) {
  pool.spawn(transform.x + transform.w / 2.0f, transform.y, factory, ctx);
  shootTimer = shootCooldown;
}

const bool Player::getWasSafe() const { return this->wasActivateSafe; }

void Player::switchSafeStatus() {
  this->wasActivateSafe = !this->wasActivateSafe;
}
