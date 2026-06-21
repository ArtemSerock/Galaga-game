#include "big_guy_pool.h"
#include "GameContext.h"
#include "big_guy.h"
#include "entityFactory.h"
#include "physic.h"

void BigGuyPool::spawn(EntityFactory &factory, const GameContext &ctx,
                       float playerX, float playerY) {
  float spawnX = 0.0f;
  float spawnY = 0.0f;

  const float SAFE_DISTANCE = 100.0f;
  const int MAX_ATTEMPTS = 10;

  bool validPosition = false;

  for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
    spawnX = (float)SDL_rand((int)ctx.width);
    spawnY = (float)SDL_rand((int)(ctx.height / 3));

    const std::array<float, 2> velocity = {spawnX - playerX, spawnY - playerY};
    float distance = Physic::length2D(velocity);

    if (distance >= SAFE_DISTANCE) {
      validPosition = true;
      break;
    }
  }

  if (!validPosition) {
    spawnX = 0.0f;
    spawnY = 0.0f;
  }

  for (auto &slot : pool) {
    if (!slot) {
      slot = factory.createEntity<BigGuy>(spawnX, spawnY, ctx.renderer);
      return;
    }

    if (!slot->isActive()) {
      slot->SetPosition(spawnX, spawnY);
      slot->activate();
      return;
    }
  }
}

void BigGuyPool::update(float dt, const GameContext &ctx) {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->update(dt, ctx);
    }
  }
}

void BigGuyPool::draw(SDL_Renderer *renderer) const {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->draw(renderer);
    }
  }
}

void BigGuyPool::killAll() {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->deactivate();
    }
  }
}
