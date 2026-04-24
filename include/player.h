#ifndef PLAYER_H
#define PLAYER_H

#include "GameContext.h"
#include "entity.h"

/**
 * @brief Класс корабля игрока
 *
 * Класс реализует передвижение и отрисовку корабля игрока
 */
class Player : public Entity {
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
   */
  void update(float dt, const GameContext &ctx) override;

  /**
   * @brief Деструктор
   *
   */
  ~Player();
};

#endif
