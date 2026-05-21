#ifndef BEE_H
#define BEE_H
#include "GameContext.h"
#include "entity.h"

/**
 * @brief Класс корабля примитивного врага
 *
 * Класс реализует перемещение и отрисовку Пчелы
 */
class Bee : public Entity {
public:
  /**
   * @brief Конструктор класса
   * @param tex Текстура корабля
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   * @param config Обработчик конфигурации
   */
  Bee(SDL_Texture *tex, float x, float y, const EntityConfig &config);

  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- разница во времени между кадрами
   * @param ctx Игровой контекст
   */
  void update(float dt, const GameContext &ctx) override;

  /**
   * @brief Деструктор класса
   */
  ~Bee() override;

  /**
   * @brief Установка позиции для Пчелы
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   */
  void SetPosition(float x, float y);

private:
  float t = 0.0f;
  float x;
  float y;
  float speed = 0.4f;
  SDL_FPoint p0, p1, p2, p3;

  /**
   * @brief Генерация маршрута для врага
   *
   * Этот алгоритм реализует кривые Безье
   * @param ctx Игровой контекст
   */
  void generateNewPath(const GameContext &ctx);
};

#endif
