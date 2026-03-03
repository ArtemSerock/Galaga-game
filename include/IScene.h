#ifndef ISCENE_H
#define ISCENE_H

#include "GameContext.h"
#include <SDL3/SDL.h>
#include <memory>

/**
 * @brief Интерфей сцен
 *
 */
class IScene {
public:
  /**
   * @brief Чисто виртуальный деструктор
   *
   */
  virtual ~IScene() = default;

  /**
   * @brief Обработка событий
   *
   * @param ctx игровой контекст
   * @param event Событие
   */
  virtual void handleEvent(GameContext &ctx, const SDL_Event &event) = 0;

  /**
   * @brief Обновление сцены каждый кадр
   *
   * @param ctx Игровой контекст
   * @param deltaTime Время, прошедшее с предыдущего кадра
   */
  virtual void update(GameContext &ctx, float deltaTime) = 0;

  /**
   * @brief Отрисовка сцены
   *
   * @param ctx Игровой контекст
   */
  virtual void render(GameContext &ctx) const = 0;
};

#endif // ISCENE_H
