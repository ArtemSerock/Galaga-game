#ifndef GAME_H
#define GAME_H

#include "GameContext.h"
#include "SDL3/SDL_init.h"
#include <SDL3/SDL.h>
#include <string_view>

/**
 * @brief Основной класс игры
 *
 * Отвечает за инициализацию, обработку событий и правильный выход
 */
class Game {
public:
  Game();
  ~Game();

  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

  /**
   * @brief Инициализация игры
   *
   * @param title Название игры
   */
  SDL_AppResult Init(std::string_view title);
  /**
   * @brief Обработка событий
   */
  SDL_AppResult HandleEvents(SDL_Event *event);
  /**
   * @brief Обработка вычислений
   */
  void Update();

  /**
   * @brief Отрисока
   */
  void Render();

private:
  /**
   * @brief Очистка памяти
   */
  void Clean();

  uint64_t lastTicks = 0;

  GameContext ctx;
};

#endif // GAME_H
