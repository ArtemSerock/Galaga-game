#include "score_manager.h"

void ScoreManager::addScore(int value) {
  score += value;
  pushUpdateEvent();
}

int ScoreManager::getScore() const { return this->score; }

void ScoreManager::pushUpdateEvent() {
  if (SDL_EVENT_SCORE_CHANGED != (Uint32)-1) {
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_EVENT_SCORE_CHANGED;
    event.user.code = score;
    SDL_PushEvent(&event);
  }
}

void ScoreManager::init(int max_scores) { max_scores = max_scores; }

int ScoreManager::getMaxScores() const { return max_scores; }
