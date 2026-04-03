#ifndef ENTITY_H
#define ENTITY_H

#include <SDL3/SDL.h>
#include <memory>
#include <string>

/**
 * @brief Конфигурации сущностей
 */
struct EntityConfig {
  float hp;
  float speed;
  float width;
  float height;
};

/**
 * @brief Базовый класс игровой сущности.
 */
class Entity {
protected:
  SDL_Texture *asset;  ///< Текстура объекта
  SDL_FRect transform; ///< Позиция и размер

  float hp;           ///< здоровье
  float speed;        ///< скорость пикселей в секунду
  bool active = true; ///< флаг для удаления из игрового цикла

public:
  /**
   * @brief конструктор класса
   * @param tex текстура
   * @param x координата по горизонтали
   * @param y координата по вертикали
   * @param Конфигурации из JSON файла
   */
  Entity(SDL_Texture *tex, float x, float y, const EntityConfig &config);

  /**
   * @brief деструктор
   */
  virtual ~Entity() = default;

  Entity(const Entity &) = delete;
  Entity &operator=(const Entity &) = delete;

  /**
   * @brief Обновление логики.
   * @param dt Delta Time (время в секундах с прошлого кадра).
   */
  virtual void update(float dt) = 0;

  /**
   * @brief логика отрисовки.
   * @param renderer рендер окна
   */
  virtual void draw(SDL_Renderer *renderer) const;

  /**
   * @brief проверка на активность
   * @return true, если объект активен, false -- иначе
   */
  bool isActive() const;

  /**
   * @brief отключение объекта
   */
  void deactivate();

  /**
   * @brief получение координат и размера объекта
   * @return массив из x, y, weight, height
   */
  const SDL_FRect &getRect() const;

  /**
   * @brief нанесение урона
   * @param amount Урон, который будет нанесён
   */
  virtual void takeDamage(float amount);
};

#endif
