#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H
#include <SDL3/SDL.h>

inline const Uint32 SDL_EVENT_SCORE_CHANGED = SDL_RegisterEvents(1);

/**
 * @brief Менеджер очков
 */
class ScoreManager {
private:
  int score = 0; ///< очки

  /**
   * @brief Конструктор
   */
  ScoreManager() = default;
  /*
   * @brief Деструктор
   */
  ~ScoreManager() = default;
  ScoreManager(const ScoreManager &) = delete;
  ScoreManager &operator=(const ScoreManager &) = delete;

public:
  /**
   * @brief Глобальная точка доступа
   */
  static ScoreManager &getInstance() {
    static ScoreManager instance;
    return instance;
  }

  /**
   * @brief Добавление очков
   */
  void addScore(int value);

  /**
   * @brief Получение очков
   */
  int getScore() const;

private:
  /**
   * @brief отправка сообщений
   */
  void pushUpdateEvent();
};

#endif
