#ifndef GAME_H
#define GAME_H


#include <SDL3/SDL.h>
#include "GameContext.h"
/**
 * @brief Основной класс игры
 * 
 * Отвечает за инициализацию, обработку событий и правильный выход
 */
class Game {
public:
    Game();
    ~Game();

    /**
     * @brief Инициализация игры
     * 
     * @param title Название игры
     * @param width Длина окна
     * @param height ширина окна
     * @return true Успешная инициализация
     * @return false Ошибка при инициализации
     */
    bool Init(const char* title, int width, int height);
    
    /**
     * @brief Обработка событий
     * 
     */
    void HandleEvents();
    
    /**
     * @brief Обновление окна
     * 
     */
    void Update();
    
    /**
     * @brief отрисовка кадра
     * 
     */
    void Render();
    
    /**
     * @brief Очистка памяти
     * 
     */
    void Clean();

private:
    GameContext ctx;
};

#endif // GAME_H