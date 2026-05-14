#ifndef PLAYER_H
#define PLAYER_H

#include "GameContext.h"
#include "entity.h"

class BulletPool;
class EntityFactory;
/**
 * @brief Класс корабля игрока
 *
 * Класс реализует передвижение и отрисовку корабля игрока
 */
class Player : public Entity {
private:
  float shootCooldown = 0.25f;
  float shootTimer = 0.0f;

public:
  /**
   * @brief Конструктор класса
   * @param tex текстура корабля
   * @param x координата по горизонтали
   * @param y координата по вертикали
   * @param config Обработчик конфигурации
   */
  Player(SDL_Texture *tex, float x, float y, const EntityConfig &config);
  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- разница во времени между кадрами
   * @param pool Пул объектов
   * @param factory Фабрика объектов
   */
  void update(float dt, const GameContext &ctx, BulletPool &pool,
              EntityFactory &factory);
  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- разница во времени между кадрами
   */
  void update(float dt, const GameContext &ctx) override;

  /**
   * @brief Деструктор
   *
   */
  ~Player();

  /**
   * @brief Обработка стрельбы игрока
   * @param pool Пул объектов
   * @param factory фабрика объектов
   */
  void shoot(BulletPool &pool, EntityFactory &factory, const GameContext &ctx);
};

#endif
