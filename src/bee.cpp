#include "bee.h"
#include "GameContext.h"
#include "entity.h"
#include "physic.h"

Bee::Bee(SDL_Texture *tex, float x, float y, const EntityConfig &config)
    : Entity(tex, x, y, config) {
  p0 = {x, y};
  p1 = p2 = p3 = p0;
  t = 1.0f;
}

Bee::~Bee() { SDL_DestroyTexture(this->asset); }

void Bee::update(float dt, const GameContext &ctx) {
  if (t >= 1.0f) {
    generateNewPath(ctx);
  }

  t += speed * dt;
  if (t >= 1.0f) {
    float overflow = t - 1.0f;
    generateNewPath(ctx);
    t = overflow;
  }
  SDL_FPoint nextPos = Physic::bezierPoints(p0, p1, p2, p3, t);

  transform.x = nextPos.x;
  transform.y = nextPos.y;
}

void Bee::generateNewPath(const GameContext &ctx) {
  SDL_FPoint oldP2 = p2;
  bool isFirstSpawn = (p0.x == p3.x && p0.y == p3.y && p1.x == p3.x);

  p0 = p3;

  float maxX = ctx.width - transform.w;
  float maxY = ctx.height - transform.h;

  if (!isFirstSpawn) {
    p1.x = 2.0f * p0.x - oldP2.x;
    p1.y = 2.0f * p0.y - oldP2.y;
    if (p1.x < 0.0f)
      p1.x = 0.0f;
    if (p1.x > maxX)
      p1.x = maxX;
    if (p1.y < 0.0f)
      p1.y = 0.0f;
    if (p1.y > maxY)
      p1.y = maxY;
  } else {
    p1 = {(rand() / (float)RAND_MAX) * maxX, (rand() / (float)RAND_MAX) * maxY};
  }

  p2 = {(rand() / (float)RAND_MAX) * maxX, (rand() / (float)RAND_MAX) * maxY};
  p3 = {(rand() / (float)RAND_MAX) * maxX, (rand() / (float)RAND_MAX) * maxY};
}

void Bee::SetPosition(float x, float y) {
  transform.x = x;
  transform.y = y;
  p0 = {x, y};
  p1 = p2 = p3 = p0;
  t = 1.0f;
}
