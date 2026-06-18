#ifndef BIG_GUY_POOL_H
#define BIG_GUY_POOL_H

#include "GameContext.h"
#include "big_guy.h"
#include "entityFactory.h"
#include <array>
#include <memory>

/**
 * @brief Пул Больших врагов
 */
class BigGuyPool {
private:
  static constexpr size_t POOL_SIZE = 2;
  std::array<std::unique_ptr<BigGuy>, POOL_SIZE> pool;

public:
  /**
   * @brief Инициализация больших врагов
   * @param factory Фабрика сущностей
   * @param ctx Игровой контекст
   * @param playerX Координата игрока по горизонтали
   * @param playerY Координата игрока по вертикали
   */
  void spawn(EntityFactory &factory, const GameContext &ctx, float playerX,
             float playerY);

  /**
   * @brief Обработка Больших врагов
   * @param dt DeltaTime -- Задержка времени между кадрами
   * @param ctx Игровой контекст
   */
  void update(float dt, const GameContext &ctx);

  /**
   * @brief Отрисовка Больших врагов
   * @param renderer Рендер игры
   */
  void draw(SDL_Renderer *renderer) const;

  /**
   * @brief Получение пула
   * @return Пул объектов
   */
  const std::array<std::unique_ptr<BigGuy>, POOL_SIZE> &getPool() const {
    return this->pool;
  }

  /**
   * @brief Уничтожение всех Больших врагов на карте
   */
  void killAll();
};

#endif
