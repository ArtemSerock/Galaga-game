#ifndef PLAYER_BULLET_H
#define PLAYER_BULLET_H

#include "GameContext.h"
#include "particle.h"
#include "particleConfig.h"
#include <string>

/**
 * @brief Класс пули игрока
 */
class PlayerBullet : public Particle {
  const std::string type = "player_bullet"; ///< Тип частицы
public:
  /**
   * @brief Конструктор Класса
   * @param tex Текстура
   * @param x Координата по горизонтали
   * @param y Координата по веритикали
   * @param config Конфигурация из JSON файла
   */
  PlayerBullet(SDL_Texture *tex, float x, float y,
               const ParticleConfig &config);

  PlayerBullet(const PlayerBullet &) = delete;
  PlayerBullet(PlayerBullet &&) = default;
  PlayerBullet &operator=(PlayerBullet &&) = default;
  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- разница во времени между кадрами
   */
  void update(float dt, const GameContext &ctx) override;
};

#endif
