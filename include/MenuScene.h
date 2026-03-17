#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "GameContext.h"
#include "IScene.h"

class MenuScene : public IScene {
public:
  void handleEvent(GameContext &ctx, const SDL_Event &event) override;
  void update(GameContext &ctx, float deltaTime) override;
  void render(GameContext &ctx) const override;
};
#endif
