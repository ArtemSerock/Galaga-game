#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H
#include "IScene.h"
#include <SDL3/SDL.h>
#include <memory>

enum class SceneType { NONE, MENU, GAME, GAME_OVER };

/**
 * @brief Игровой контекст
 *
 * Данная структура хранит Основные параметры игры,
 * такие как длина и ширина окна, указатель на объект окна и рендера
 * и текущую сцену
 */
struct GameContext {
  SDL_Renderer *renderer = nullptr;      //< Рендер игры
  SDL_Window *window = nullptr;          //< Окно игры
  int width = 1000;                       //< Длина экрана
  int height = 800;                      //< Ширина экрана
  SceneType nextScene = SceneType::MENU; //< Следующая сцена

  std::unique_ptr<IScene> activeScene = nullptr; //< Текущая сцена

  /**
   * Конструкторы запрещают копирование, чтобы избежать двойного удаления
   * указателей
   *
   */
  GameContext() = default;
  GameContext(const GameContext &) = delete;
  GameContext &operator=(const GameContext &) = delete;

  /**
   * @brief Декструктор, созданный для удаления указателей
   *
   */
  ~GameContext() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
  }

  /**
   * @brief Переключает на следующую сцену
   *
   * переключает текущую сцену на ту, что записана в nextScene
   */
  void updateScene();
};

#endif
