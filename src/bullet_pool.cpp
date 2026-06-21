#include "bullet_pool.h"
#include "GameContext.h"
#include "entityFactory.h"
#include "player_bullet.h"

void BulletPool::spawn(float x, float y, EntityFactory &factory,
                       const GameContext &ctx) {
  for (auto &slot : pool) {
    if (!slot) {
      slot = factory.createEntity<PlayerBullet>(x, y, ctx.renderer);
      return;
    }

    if (!slot->isActive()) {
      slot->setPosition(x, y);
      slot->activate();

      return;
    }
  }
}

void BulletPool::update(float dt, const GameContext &ctx) {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->update(dt, ctx);
    }
  }
}

void BulletPool::draw(SDL_Renderer *render) const {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->draw(render);
    }
  }
}
