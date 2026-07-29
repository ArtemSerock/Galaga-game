#include "super_bomb.h"
#include "SDL3/SDL_render.h"
#include "physic.h"

SuperBomb::SuperBomb(SDL_Texture *tex, float radius, float duration)
    : tex(tex), radius(radius), animation_duration(duration),
      tex_rect({0, 0, 0, 0}), animation_timer(0.0f) {}

bool SuperBomb::isActive() const { return this->is_active; }

void SuperBomb::spawn(float x, float y) {
  animation_timer = animation_duration;
  is_active = true;
  tex_rect = Physic::getRectFromCircle(x, y, radius);
}

void SuperBomb::update(float dt) {
  if (!is_active) {
    return;
  }
  if (animation_timer > 0) {
    animation_timer -= dt;
  }

  if (animation_timer <= 0) {
    is_active = false;
  }
}

const SDL_FRect &SuperBomb::getRect() const { return this->tex_rect; }

void SuperBomb::draw(SDL_Renderer *renderer) const {
  if (!is_active) {
    return;
  }
  SDL_RenderTexture(renderer, tex, NULL, &tex_rect);
}
