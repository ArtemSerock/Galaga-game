#ifndef WIN_SCENE
#define WIN_SCENE

#include "GameContext.h"
#include "IScene.h"
#include "assetManager.h"

/**
 * @brief Сцена Победы
 */
class WinScene : public IScene {
private:
  AssetManager am;       ///< Менеджер ассетов
  SDL_Texture *message;  ///< Текстура сообщения о победе
  SDL_FRect meessgeRect; ///< Позиция и размеры сообщения о победе

public:
  /**
   * @brief Конструктор класса
   *
   * Загружает необходимые текстуры
   */
  WinScene(const GameContext &ctx);

  /**
   * @brief Деструктор
   */
  ~WinScene();

  /**
   * @brief Обработка входящий событий
   *
   * @param ctx Игровой контекст
   * @param event Входящее событие
   */
  void handleEvent(GameContext &ctx, const SDL_Event &event) override;

  /**
   * @brief Обработка вычислений
   * @param ctx Игровой контекст
   * @param deltaTime Задержка времени между кадрами
   */
  void update(GameContext &ctx, float deltaTime) override;

  /**
   * @brief Отрисовка текущей сцены
   *
   * @param ctx Игровой контекст
   */
  void render(GameContext &ctx) const override;
};

#endif
