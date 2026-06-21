#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "assetManager.h"
#include "particleConfig.h"
#include "player.h"
#include <iostream>
#include <memory>
#include <nlohmann/json.hpp>
#include <particle.h>
#include <string>

template <typename T>
concept IsEnemyOrParticle =
    std::is_base_of_v<Entity, T> || std::is_base_of_v<Particle, T>;

/**
 * @brief Фабрика сущностей
 *
 * создаёт сущности разных типов, используя данные из ConfigManager
 */
class EntityFactory {
private:
  AssetManager &manager;
  const nlohmann::json &configData;

public:
  /**
   * @brief конструктор класса
   * @param am Менеджер ассетов
   * @param configKey ключ конфигурации в ConfigManager
   */
  EntityFactory(AssetManager &am, const std::string &configKey = "entities");

  /**
   * @brief создание объекта
   */
  template <IsEnemyOrParticle T>
  std::unique_ptr<T> createEntity(float x, float y, SDL_Renderer *renderer) {
    constexpr std::string type = T::getType();
    if (!configData.contains(type)) {
      std::cerr << "FACTORY ERROR: Type '" << type
                << "' not found in JSON config!" << std::endl;
      return nullptr;
    }

    const auto &cfg = configData.at(type);

    std::string texPath = cfg.value("asset", "assets/placeholder.png");
    SDL_Texture *tex = manager.getTexture(texPath, renderer);

    if constexpr (std::derived_from<T, Entity>) {
      EntityConfig eConfig;
      eConfig.hp = cfg.value("hp", 100.0f);
      eConfig.speed = cfg.value("speed", 100.0f);
      eConfig.width = cfg.value("width", 32.0f);
      eConfig.height = cfg.value("height", 32.0f);

      return std::make_unique<T>(tex, x, y, eConfig);

    } else if constexpr (std::derived_from<T, Particle>) {
      ParticleConfig pConfig;
      pConfig.height = cfg.value("height", 25.0);
      pConfig.width = cfg.value("width", 10.0);
      pConfig.vel_x = cfg.value("vel_x", 0.0);
      pConfig.vel_y = cfg.value("vel_y", -700.0);

      return std::make_unique<T>(tex, x, y, pConfig);
    }

    return nullptr;
  }
};

#endif
