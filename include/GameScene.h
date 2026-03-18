#include "IScene.h"


/**
 * @brief Класс сцены Основной игры
 * 
 * Здесь обрабатываются все входящие в эту сцену события
 * и проводятся соответствующие вычисления
 */
class GameScene : public IScene {
public:
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
