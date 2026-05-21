#ifndef PHYSIC_H
#define PHYSIC_H
#include <SDL3/SDL_rect.h>
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
    p.x = uuu * p0.x + 3 * uu * t * p1.x + 3 * u * tt * p2.x + ttt * p3.x;
    p.y = uuu * p0.y + 3 * uu * t * p1.y + 3 * u * tt * p2.y + ttt * p3.y;

    return p;
  }
};

#endif
