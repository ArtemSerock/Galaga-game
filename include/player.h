#ifndef PLAYER_H
#define PLAYER_H

#include "GameContext.h"
#include "entity.h"
#include <string>

class BulletPool;
class EntityFactory;
/**
 * @brief Класс корабля игрока
 *
 * Класс реализует передвижение и отрисовку корабля игрока
 */
class Player : public Entity {
private:
  float shootCooldown =
      0.25f;               ///< Время, которое должно пройти между выстрелами
  float shootTimer = 0.0f; ///< Таймер до выстрела

  bool wasActivateSafe =
      false; ///< Статус спасения игрока от мгновенного поражения

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
   * @param ctx Игровой контекст
   * @param pool Пул объектов
   * @param factory Фабрика объектов
   */
  void update(float dt, const GameContext &ctx, BulletPool &pool,
              EntityFactory &factory);
  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- разница во времени между кадрами
   * @param ctx Игровой контекст
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

  /**
   * @brief Выводит, сработало ли спасение от гибели
   * @return true -- если спасение уже было использовано, false -- иначе
   */
  const bool getWasSafe() const;

  /**
   * @brief Переключение статуса спасения игрока от мгновенного поражения
   */
  void switchSafeStatus();

  void takeDamage(float amount) override;

  /**
   * @brief Получение типа
   */
  static constexpr const std::string getType() { return "player"; }
};

#endif
