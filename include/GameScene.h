#include "IScene.h"

class GameScene : public IScene {
public:
  void handleEvent(GameContext &ctx, const SDL_Event &event) override;
  void update(GameContext &ctx, float deltaTime) override;
  void render(GameContext &ctx) const override;
};
