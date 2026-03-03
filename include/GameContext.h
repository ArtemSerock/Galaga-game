#ifndef GAME_CONTEXT_H
#define GAME_CONTEXT_H
#include <SDL3/SDL.h>

enum class SceneType { NONE, MENU, GAME, GAME_OVER };

/**
 * @brief Игровой контекст
 *
 * Данная структура хранит Основные параметры игры,
 * такие как длина и ширина окна, указатель на объект окна и рендера
 * и текущую сцену
 */
struct GameContext {
  SDL_Renderer *renderer = nullptr; //< Рендер игры
  SDL_Window *window = nullptr;     //< Окно игры
  int width = 800;              //< Длина экрана
  int height = 600;             //< Ширина экрана
  SceneType nextScene = SceneType::MENU;    //< Следующая сцена
  SceneType currentScene = SceneType::NONE; //< текущая сцена

  /**
   * Конструкторы запрещают копирование, чтобы избежать двойного удаления указателей
   * 
   */
  GameContext() = default;
    GameContext(const GameContext&) = delete;
    GameContext& operator=(const GameContext&) = delete;

    /**
     * @brief Декструктор, созданный для удаления указателей
     * 
     */
    ~GameContext(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }


};

#endif