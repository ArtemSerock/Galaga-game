#ifndef GAME_H
#define GAME_H

#include "GameContext.h"
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

  // Запрет копирования (RAII)
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

  /**
   * @brief Инициализация игры
   *
   * @param title Название игры
   * @param width Ширина окна
   * @param height Высота окна
   * @return true Успешная инициализация
   * @return false Ошибка при инициализации
   */
  bool Init(std::string_view title, int width, int height);

  void HandleEvents();
  void Update();
  void Render();

private:
  /**
   * @brief Очистка памяти
   */
  void Clean();

  GameContext ctx;
};

#endif // GAME_H
