#ifndef PHYSIC_H
#define PHYSIC_H
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
};

#endif
