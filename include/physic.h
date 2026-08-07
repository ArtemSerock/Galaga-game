#ifndef PHYSIC_H
#define PHYSIC_H
#include <SDL3/SDL.h>
#include <array>
#include <cmath>

/**
 * @brief Класс, реализующий неизменные свойства физики
 */
class Physic {
public:
  /**
   * @brief расчёт длины двумерного вектора
   * @param arr массив из двух элементов
   * @return длина вектора
   */
  static inline float length2D(const std::array<float, 2> &arr) {
    return std::sqrt(arr[0] * arr[0] + arr[1] * arr[1]);
  }

  /**
   * @brief Нормализация вектора
   *
   * Нормализация -- приведение вектора к коллинеарному длины 1
   * @param arr вектор, который нужно нормализовать
   * @return нормализованный вектор
   */
  static inline void normalize2D(std::array<float, 2> &arr) {
    float length = length2D(arr);
    for (size_t i = 0; i < arr.size(); i++) {
      arr[i] /= length;
    }
  }

  /**
   * @brief Вычисление координат дуг Безье
   * @param p0,p1,p2,p3 точки
   * @param t Время, за которое точка проходит по дуге
   * @return точки дуги в зависимости от t
   */
  static inline SDL_FPoint bezierPoints(const SDL_FPoint &p0,
                                        const SDL_FPoint &p1,
                                        const SDL_FPoint &p2,
                                        const SDL_FPoint &p3, float t) {
    float u = 1.0f - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    SDL_FPoint p;
    // Здесь мы используем формулу Безье
    p.x = uuu * p0.x + 3 * uu * t * p1.x + 3 * u * tt * p2.x + ttt * p3.x;
    p.y = uuu * p0.y + 3 * uu * t * p1.y + 3 * u * tt * p2.y + ttt * p3.y;

    return p;
  }

  /**
   * @brief Проверка коллизии
   * @param rect1 Первый прямоугольник
   * @param rect2 второй прямоугольник
   *
   * @return true -- если прямоугольники соприкасаются, false -- иначе
   */
  static inline bool isCollision(const SDL_FRect &rect1,
                                 const SDL_FRect &rect2) noexcept {
    return SDL_HasRectIntersectionFloat(&rect1, &rect2);
  }

  /**
   * @brief Нахождение координаты левого верхнего угла
   * Контекст:
   *   Для некоторых задач необходимо построить окружность вокруг объекта
   *   в SDL3 все текстуры представлены в виде прямоугольника,
   *   поэтому необходим способ перевести координаты центра окружности и радиус
   * в прямоугольник
   *
   * @param center_x Координата центра окружности по горизонтали
   * @param center_y Координата центра окружности по вертикали
   * @param radius Радиус окружности
   *
   * @return Прямоугольник, описанный около окружности
   */
  static inline SDL_FRect getRectFromCircle(float center_x, float center_y,
                                            float radius) {
    float side = 2 * radius;
    return {center_x - radius, center_y - radius, side, side};
  }
};

#endif
