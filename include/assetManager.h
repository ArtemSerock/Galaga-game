#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <map>
#include <string>

/**
 * @brief Менеджер текстур
 *
 * Скачивает и удаляет текстуры
 */
class AssetManager {
private:
  std::map<std::string, SDL_Texture *> textures; ///< все загруженные текстуры

public:
  /**
   * @brief деструктор класса
   */
  ~AssetManager();

  /**
   * @brief Конструктор по умолчанию
   *
   */
  AssetManager();

  AssetManager(const AssetManager &) = delete;
  AssetManager &operator=(const AssetManager &) = delete;

  /**
   * @brief получение текстуры
   * @param path путь к текстуре
   * @param renderer рендер игры
   * @return текстура
   */
  SDL_Texture *getTexture(const std::string &path, SDL_Renderer *renderer);
};

#endif
