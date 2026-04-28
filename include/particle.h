#ifndef PARTICLE_H
#define PARTICLE_H

#include "GameContext.h"
#include "particleConfig.h"
#include <SDL3/SDL.h>

/**
 * @brief Базовый класс частиц
 */
class Particle {
public:
  /**
   * @brief Конструктор класса
   * @param tex Текстура
   * @param x Координата по горизонтали
   * @param y Координата по веритикали
   * @param config Конфигурация из JSON файла
   */
  Particle(SDL_Texture *tex, float x, float y, const ParticleConfig &config);

  /**
   * @brief Деструктор
   */
  ~Particle();

  Particle(const Particle &) = delete;
  Particle operator=(const Particle &) = delete;

  /**
   * @brief Обновление логики
   * @param dt Delta Time(Время в секундах с прошлого кадра)
   * @param ctx Игровой контекст
   */
  virtual void update(float dt, const GameContext &ctx) = 0;

  /**
   * @brief Логика отрисовки
   * @param renderer Рендер окна
   */
  virtual void draw(SDL_Renderer *renderer) const;

  /**
   * @brief Проверка на активность
   * @return true, если частица активна, false -- иначе
   */
  bool isActive() const;

  /**
   * @brief Отключение частицы
   */
  void deactivate();

  /**
   * @brief Включение частицы
   */
  void activate();

  /**
   * @brief Получение координат частицы
   * @return массив из x, y, weight, weight
   */
  const SDL_FRect &getRect() const;

protected:
  SDL_Texture *tex;    ///< Текстура частицы
  SDL_FRect transform; ///< Позиция и размер
  bool active = false; ///< Флаг для удаления из игрового цикла

  float velocity_y; ///< Скорость по веритикали в пикселях в секунду
  float velocity_x; ///< Скорость по горизонтали в пикселях в секунду
};
#endif // !PARTICLE_H
