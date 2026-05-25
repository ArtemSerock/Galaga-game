#ifndef FINAL_SCENE_H
#define FINAL_SCENE_H

#include "IScene.h"
#include <SDL3/SDL.h>

/**
 * @brief Класс сцены конца игры
 *
 * Здесь выводится сообщение о конце
 */
class FinalScene : public IScene {
private:
  SDL_Texture *message;
  SDL_FRect messageRect;

public:
  /**
   * @brief Конструктор класса меню
   *
   * Загружает необходимые текстуры
   */
  FinalScene(GameContext &ctx);

  /**
   * @brief Деструктор класс меню
   *
   * Удаляет из памяти всё загруженное
   */
  ~FinalScene();
  /**
   * @brief Обработка входящих событий
   *
   * @param ctx Игровой контекст
   * @param event входящее событие
   */
  void handleEvent(GameContext &ctx, const SDL_Event &event) override;

  /**
   * @brief Обработка вычислений текущей сцены
   *
   * @param ctx игровой контекст
   * @param deltaTime задержка времени между кадрами
   */
  void update(GameContext &ctx, float deltaTime) override;

  /**
   * @brief Отрисовка текущей сцены
   *
   * @param ctx игровой контекст
   */
  void render(GameContext &ctx) const override;
};

#endif
