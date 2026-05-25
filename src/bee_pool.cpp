#include "bee_pool.h"
#include "GameContext.h"
#include "entityFactory.h"
#include <memory>

void BeePool::spawn(float x, float y, EntityFactory &factory,
                    const GameContext &ctx) {
  for (auto &slot : pool) {
    if (!slot) {
      slot = factory.createEntity<Bee>("bee", x, y, ctx.renderer);
      return;
    }

    if (!slot->isActive()) {
      slot->SetPosition(x, y);
      slot->activate();
      return;
    }
  }
}

void BeePool::update(float dt, const GameContext &ctx) {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->update(dt, ctx);
    }
  }
}

void BeePool::draw(SDL_Renderer *renderer) const {
  for (auto &slot : pool) {
    if (slot && slot->isActive()) {
      slot->draw(renderer);
    }
  }
}
