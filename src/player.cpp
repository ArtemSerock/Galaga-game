#include "player.h"
#include "GameContext.h"
#include "bullet_pool.h"
#include "entity.h"
#include "entityFactory.h"
#include "physic.h"
#include <SDL3/SDL.h>
#include <algorithm>
#include <array>
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

  std::array<float, 2> direction = {0.0f, 0.0f};

  if (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT])
    direction[0] -= 1.0f;
  if (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT])
    direction[0] += 1.0f;
  if (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP])
    direction[1] -= 1.0f;
  if (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN])
    direction[1] += 1.0f;

  float length = Physic::length2D(direction);
  if (length > 0.0f) {
    Physic::normalize2D(direction);
  }

  // Стрельба
  if (keys[SDL_SCANCODE_SPACE] && shootTimer <= 0.0f) {
    this->shoot(pool, factory, ctx);
    std::cout << "SHOOT" << std::endl;
  }
  this->transform.x += direction[0] * speed_per_second;
  this->transform.y += direction[1] * speed_per_second;

  // Удержание игрока в рамках игрового поля
  this->transform.x =
      std::max(0.0f, std::min(transform.x, ctx.width - transform.w));

  this->transform.y =
      std::max(0.0f, std::min(transform.y, ctx.height - transform.h));
}

void Player::update(float dt, const GameContext &ctx) {
  Entity::update(dt, ctx);
}

Player::~Player() { SDL_DestroyTexture(this->asset); }

void Player::shoot(BulletPool &pool, EntityFactory &factory,
                   const GameContext &ctx) {
  pool.spawn(transform.x + transform.w / 2.0f, transform.y, "player_bullet",
             factory, ctx);
  shootTimer = shootCooldown;
}
