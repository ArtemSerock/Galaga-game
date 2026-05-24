#ifndef BEE_POOL_H
#define BEE_POOL_H

#include "GameContext.h"
#include "bee.h"
#include <array>
#include <memory>
class EntityFactory;

/**
 * @brief Пул Пчёл
 */
class BeePool {
private:
  static constexpr size_t POOL_SIZE = 20;
  std::array<std::unique_ptr<Bee>, POOL_SIZE> pool;

public:
  /**
   * @brief Инициализация врагов
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   * @param factory Фабрика сущностей
   * @param ctx Игровой контекст
   */
  void spawn(float x, float y, EntityFactory &factory, const GameContext &ctx);

  /**
   * @brief Обработка Пчёл
   * @param dt Delta Time -- Задержка времени между кадрами
   * @param ctx Игровой контекст
   */
  void update(float dt, const GameContext &ctx);

  /**
   * @brief Отрисовка Пчёл
   * @param renderer Обработчик окон
   */
  void draw(SDL_Renderer *renderer) const;

  /**
   * @brief Получение пула
   * @return Пул объектов
   */
  const std::array<std::unique_ptr<Bee>, POOL_SIZE> &getPool() const;
};

#endif
