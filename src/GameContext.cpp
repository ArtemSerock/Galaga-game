#include "GameContext.h"
#include "GameScene.h"
#include "MenuScene.h"
#include <memory>

void GameContext::updateScene() {
  if (nextScene == SceneType::NONE)
    return;

  switch (nextScene) {
  case SceneType::MENU:
    activeScene = std::make_unique<MenuScene>(*this);
    break;
  case SceneType::GAME:
    activeScene = std::make_unique<GameScene>(*this);
    break;
  default:
    break;
  }
  nextScene = SceneType::NONE;
}
