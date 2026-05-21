#include "bee.h"
#include "GameContext.h"
#include "entity.h"
#include "physic.h"

Bee::Bee(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : Entity(tex, x, y, config) {
  p0 = {x, y};
  p1 = p2 = p3 = p0;
}

Bee::~Bee() { SDL_DestroyTexture(this->asset); }

void Bee::update(float dt, const GameContext &ctx) {
  if ((p0.x == p3.x && p0.y == p3.y) || t >= 1.0f) {
    generateNewPath(ctx);
  }

  t += speed * dt;
  if (t > 1.0f) {
    t = 1.0f;
  }

  SDL_FPoint nextPos = Physic::bezierPoints(p0, p1, p2, p3, t);

  transform.x = nextPos.x;
  transform.y = nextPos.y;
}

void Bee::generateNewPath(const GameContext &ctx) {
  p0 = {x, y};

  float w = ctx.width;
  float h = ctx.height;

  p1 = {static_cast<float>(rand() % static_cast<int>(w)),
        static_cast<float>(rand() % static_cast<int>(h))};
  p2 = {static_cast<float>(rand() % static_cast<int>(w)),
        static_cast<float>(rand() % static_cast<int>(h))};
  p3 = {static_cast<float>(rand() % static_cast<int>(w)),
        static_cast<float>(rand() % static_cast<int>(h))};

  t = 0.0f;
}

void Bee::SetPosition(float x, float y) {
  transform.x = x;
  transform.y = y;
}
