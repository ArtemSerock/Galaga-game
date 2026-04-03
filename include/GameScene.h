#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameContext.h"
#include "IScene.h"
#include "player.h"
#include <memory>
#include "assetManager.h"
#include "entityFactory.h"

/**
 * @brief Класс сцены Основной игры
 *
 * Здесь обрабатываются все входящие в эту сцену события
 * и проводятся соответствующие вычисления
 */
class GameScene : public IScene {
private:
  AssetManager am;
  EntityFactory factory;
  std::unique_ptr<Player> player;

public:
  /**
   * @brief Конструктор класса
   * Загрузка текстур и создание объектов
   */
  GameScene(GameContext &ctx);
  /**
   * @brief Обработка входящих событий
   *
   * @param ctx Игровой контекст
   * @param event входящее событие
   */
  void handleEvent(GameContext &ctx, const SDL_Event &event) override;

  /**
   * @brief Обработка вычислений текущей сцены
   *
   * @param ctx игровой контекст
   * @param deltaTime задержка времени между кадрами
   */
  void update(GameContext &ctx, float deltaTime) override;

  /**
   * @brief Отрисовка текущей сцены
   *
   * @param ctx игровой контекст
   */
  void render(GameContext &ctx) const override;
};


#endif