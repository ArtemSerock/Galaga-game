#ifndef BIG_GUY_H
#define BIG_GUY_H
#include "GameContext.h"
#include "entity.h"
#include <string>

/**
 * @brief Класс Большого врага
 *
 * Класс реализует перемещение и отрисовку большого врага
 */
class BigGuy : public Entity {
public:
  /**
   * @brief Конструктор класса
   * @param tex Текстура корабля
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   * @param config Обработчик конфигураций
   */
  BigGuy(SDL_Texture *tex, float x, float y, const EntityConfig &config);

  /**
   * @brief Обработка вычислений
   * @param dt DeltaTime -- разница во времени между кадрами
   * @param ctx Игровой контекст
   */
  void update(float dt, const GameContext &ctx) override;

  /**
   * @brief Деструктор класса
   */
  ~BigGuy() override;

  /**
   * @brief Установка позиции для Большого врага
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   */
  void SetPosition(float x, float y);

  /**
   * @brief Запускает эффект появления Большого врага
   */
  void startSpawnEffect();

  /**
   * @brief Переопределение метода отрисовки
   * @param renderer Рендер игры
   */
  void draw(SDL_Renderer *renderer) const override;

  /**
   * @brief Проверка готовности Большого врага
   */
  bool isReady() const;

  /**
   * @brief Получение типа
   */
  static constexpr const std::string getType() { return "big_guy"; }

private:
  bool isSpawning = true;
  float alpha = 0.0f;
  float spawnSpeed = 2.0f;
  float t = 0.0f;
  float x;
  float y;
  float speed = 0.4f;
  SDL_FPoint p0, p1, p2, p3;

  SDL_FPoint targetPoint;

  /**
   * @brief Генерация маршрута для врага
   *
   * Этот алгоритм реализует кривые Безье
   * @param ctx Игровой контекст
   */
  void generateNewPath(const GameContext &ctx);
};

#endif
