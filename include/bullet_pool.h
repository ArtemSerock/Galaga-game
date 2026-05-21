#ifndef BULLET_POOL_H
#define BULLET_POOL_H

#include "GameContext.h"
#include "player_bullet.h"
#include <array>
#include <memory>
#include <string>

class EntityFactory;
/**
 * @brief Пул пуль
 */
class BulletPool {
private:
  static constexpr size_t POOL_SIZE = 10; ///< Максимальный размер пула
  std::array<std::unique_ptr<PlayerBullet>, POOL_SIZE> pool; ///< Пул частиц

public:
  /**
   * @brief Инициализация частиц
   * @param x Координата по горизонтали
   * @param y Координата по веритикали
   * @param type Тип созданной пули
   * @param factory Фабрика сущностей
   * @param ctx Игровой контекст
   */
  void spawn(float x, float y, const std::string &type, EntityFactory &factory,
             const GameContext &ctx);

  /**
   * @brief Обработка частиц
   * @param dt Delta Time(Время в секундах с прошлого кадра)
   * @param ctx Игровой контекст
   */
  void update(float dt, const GameContext &ctx);

  /**
   * @brief Отрисовка пуль
   * @param render Обработчик окна
   */
  void draw(SDL_Renderer *render) const;
};

#endif
