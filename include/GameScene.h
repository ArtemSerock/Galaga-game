#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "GameContext.h"
#include "IScene.h"
#include "assetManager.h"
#include "bee_pool.h"
#include "bullet_pool.h"
#include "collision_manager.h"
#include "entityFactory.h"
#include "player.h"
#include <memory>

/**
 * @brief Класс сцены Основной игры
 *
 * Здесь обрабатываются все входящие в эту сцену события
 * и проводятся соответствующие вычисления
 */
class GameScene : public IScene {
private:
  AssetManager am;                      ///< Менеджер текстур
  EntityFactory factory;                ///< Фабрика объектов
  BeePool bees;                         ///< Пул пчёл
  std::unique_ptr<Player> player;       ///< Игрок
  float beeCooldown = 2.0f;             ///< Время между появлением пчёл
  float beeTimer = 0.0f;                ///< Таймер призыва пчёл
  BulletPool player_bullets;            ///< Пуль пуль игрока
  std::unique_ptr<CollisionManager> cm; ///< Менеджер коллизий

  float shakeTime = 0.0f;  ///< Таймер тряски экрана
  float shakeForce = 0.0f; ///< Сила тряски экрана

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
