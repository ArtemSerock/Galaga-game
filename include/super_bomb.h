#ifndef SUPER_BOMB_H
#define SUPER_BOMB_H

#include <SDL3/SDL.h>

/**
 * @brief Класс супер-бомбы
 *
 * Данный класс реализует супер-бомбу, которую использует игрок для упрощения
 * игрового процесса
 */
class SuperBomb {
private:
  SDL_Texture *tex;         ///< Текстура супер-бомбы
  SDL_FRect tex_rect;       ///< Rectangle текстуры
  float radius;             ///< Радиус супер-бомбы
  float animation_duration; ///< Длительность анимации
  float animation_timer;    ///< Таймер анимации
  bool is_active = false;   ///< Флаг активности
public:
  /**
   * @brief Конструктор
   * @param tex Текстура
   * @param radius Радиус
   * @param duration Задержка
   */
  SuperBomb(SDL_Texture *tex, float radius, float duration);
  SuperBomb() = default;

  /**
   * @brief Деструктор
   */
  ~SuperBomb() = default;

  /**
   * @brief Создание супер-бомбы
   * @param x Координата по горизонтали
   * @param y Координата по вертикали
   */
  void spawn(float x, float y);

  /**
   * @brief Обработка вычислений
   * @param dt Delta Time -- Задержка во времени между кадрами
   */
  void update(float dt);

  /**
   * @brief Отрисовка супер-бомбы
   * @param renderer Обработчик окна
   */
  void draw(SDL_Renderer *renderer) const;

  /**
   * @brief Проверка на активность
   * @return true, если супер-бомба активна, else -- иначе
   */
  bool isActive() const;

  /**
   * @brief Получение Rectangle текстуры
   * @return Rectangle текстуры
   */
  const SDL_FRect &getRect() const;
};

#endif
