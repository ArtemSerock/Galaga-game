#ifndef SUPER_BOMB_MANAGER_H
#define SUPER_BOMB_MANAGER_H

#include <SDL3/SDL.h>

inline const Uint32 SDL_EVENT_SUPER_BOMP_USED = SDL_RegisterEvents(1);

/**
 * @brief Менеджер Супер-бомбы
 *
 * Считает радиус и положение
 * Следит за количеством использований
 */
class SuperBombManager {
private:
  float radius; ///< Радиус взрыва
  int count;    ///< Количество использований

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
  static SuperBombManager &getInstance() {
    static SuperBombManager instance;
    return instance;
  }

  /**
   * @brief Получение количества зарядов
   */
  int getCount() const;

  /**
   * @brief Инициализация
   * @param start_count Начальное число зарядов
   */
  void init(int start_count);

  /**
   * @brief Вычитание количества зарядов
   * @param value Значение для вычитания
   */
  void SubCount(int value);
};

#endif
