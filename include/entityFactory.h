#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "assetManager.h"
#include "bee.h"
#include "big_guy.h"
#include "particleConfig.h"
#include "player.h"
#include "player_bullet.h"
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
   * @param renderer Отрисовщик окна
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

    ParticleConfig pConfig;
    pConfig.height = cfg.value("height", 25.0);
    pConfig.width = cfg.value("width", 10.0);
    pConfig.vel_x = cfg.value("vel_x", 0.0);
    pConfig.vel_y = cfg.value("vel_y", -700.0);

    if constexpr (std::is_same_v<T, Player>) {

      if (type == "player") {
        return std::make_unique<Player>(tex, x, y, eConfig);
      }

    } else if constexpr (std::is_same_v<T, PlayerBullet>) {

      if (type == "player_bullet") {
        return std::make_unique<PlayerBullet>(tex, x, y, pConfig);
      }

    } else if constexpr (std::is_same_v<T, Bee>) {

      if (type == "bee") {
        return std::make_unique<Bee>(tex, x, y, eConfig);
      }
    } else if constexpr (std::is_same_v<T, BigGuy>) {
      if (type == "big_guy") {
        return std::make_unique<BigGuy>(tex, x, y, eConfig);
      }
    }

    return nullptr;
  }
};

#endif
