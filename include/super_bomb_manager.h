#ifndef SUPER_BOMB_MANAGER_H
#define SUPER_BOMB_MANAGER_H

#include "SDL3/SDL_stdinc.h"
#include "super_bomb.h"
#include <SDL3/SDL.h>

extern const Uint32 SDL_EVENT_SUPER_BOMB_USED;

/**
 * @brief Менеджер Супер-бомбы
 *
 * Считает радиус и положение
 * Следит за количеством использований
 */
class SuperBombManager {
private:
  SuperBomb bomb;          ///< Супер-бомба
  float cooldown_duration; ///< Задержка между активациями Супер-бомбы
  float cooldown_timer;    ///< Таймер задержки между активациями
  int count;               ///< Количество использований

  /**
   * @brief Конструктор
   */
  SuperBombManager() = default;

  /**
   * @brief Деструктор
   */
  ~SuperBombManager() = default;

  SuperBombManager(const SuperBombManager &) = delete;
  SuperBombManager &operator=(const SuperBombManager &) = delete;

  /**
   * @brief Отправка событий
   */
  void pushUpdateEvent();

public:
  /**
   * @brief глобальная точка доступа
   */
  static SuperBombManager &getInstance();

  /**
   * @brief Получение количества зарядов
   */
  int getCount() const;

  /**
   * @brief Инициализация
   * @param start_count Начальное число зарядов
   */
  void init(SDL_Texture *tex);

  /**
   * @brief Активация Супер-бомбы
   * @param x координата бомбы по горизонтали
   * @param y координата бомбы по вертикали
   * @return true, если активация прошла успешно, false -- иначе
   */
  void boom(float x, float y);

  /**
   * @brief Обработка вычислений
   * @param delta_time Задержка во времени между кадрами
   */
  void update(float delta_time);

  /**
   * @brief Отрисовка
   * @param renderer Обработчик окна
   */
  void draw(SDL_Renderer *renderer);
};

#endif
