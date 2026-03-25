#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "GameContext.h"
#include "IScene.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"

/**
 * @brief Класс сцены главного меню
 *
 * Здесь обрабатываются все входящие в эту сцену события
 * и проводятся соответствующие вычисления
 */
class MenuScene : public IScene {
private:
  SDL_Texture *logo;
  SDL_FRect logoRect;

public:
  /**
   * @brief Конструктор класса меню
   *
   * Загружает необходимые текстуры
   */
  MenuScene(GameContext &ctx);

  /**
   * @brief Деструктор класс меню
   *
   * Удаляет из памяти всё загруженное
   */
  ~MenuScene();
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
