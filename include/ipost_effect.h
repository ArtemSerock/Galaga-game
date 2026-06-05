#ifndef I_POST_EFFECT_H
#define I_POST_EFFECT_H

#include <SDL3/SDL.h>

/*
 * @brief интерфейс эффектов GPU
 *
 * Данный класс описывает эффекты, связанные с GPU
 */
class IPostEffect {
public:
  /*
   * @brief деструктор класса
   */
  virtual ~IPostEffect() = default;

  /*
   * @brief Инициализация
   *
   * Создание пайплайна, загрузка шейдера
   * @param device логическое устройство
   */
  virtual void Init(SDL_GPUDevice *device) = 0;

  /*
   * @brief Обновление таймеров, анимаций и логики затухания
   * @param deltaTime -- задержка между кадрами в секундах
   */
  virtual void Update(float deltaTime) = 0;

  /*
   * @brief отрисовка текстуры
   * @param cmd буфер команд
   * @param screenTexture текстура текущего изображения
   */
  virtual void Render(SDL_GPUCommandBuffer *cmd,
                      SDL_GPUTexture *screenTexture) const = 0;

  /*
   * @brief триггер эффекта
   */
  virtual void Trigger() = 0;
};

#endif
