#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "assetManager.h"
#include "player.h"
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

/**
 * @brief Фабрика сущностей
 *
 * создаёт сущности разных типов
 */
class EntityFactory {
private:
  AssetManager &manager;
  nlohmann::json configData;

public:
  /**
   * @brief конструктор класса
   * @param am Менеджер ассетов
   * @param jsonPath путь к файлу
   */
  EntityFactory(AssetManager &am,
                const std::string &jsonPath = "configs/entities.json");

  /**
   * @brief создание объекта
   *
   * Создаёт объект нужного типа, беря его тип и выбирая соответствуюищий класс
   * @param type тип объекта
   * @param x координата по горизонтали
   * @param y координата по вертикали
   * @return указатель на объект
   */
  template <typename T>
  std::unique_ptr<T> createEntity(const std::string &type, float x, float y,
                                  SDL_Renderer *renderer) {
    if (!configData.contains(type)) {
      std::cerr << "FACTORY ERROR: Type '" << type << "' not found in JSON!"
                << std::endl;
      return nullptr;
    }

    const auto &cfg = configData.at(type);

    std::string texPath = cfg.value("asset", "assets/placeholder.png");
    SDL_Texture *tex = manager.getTexture(texPath, renderer);

    EntityConfig eConfig;
    eConfig.hp = cfg.value("hp", 100.0f);
    eConfig.speed = cfg.value("speed", 100.0f);
    eConfig.width = cfg.value("width", 32.0f);
    eConfig.height = cfg.value("height", 32.0f);

    if (type == "player") {

      return std::make_unique<Player>(tex, x, y, eConfig);
    }

    return nullptr;
  }
};

#endif
