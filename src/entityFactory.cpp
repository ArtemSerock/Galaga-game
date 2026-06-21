#include "entityFactory.h"

EntityFactory::EntityFactory(AssetManager &am, const std::string &configKey)
    : manager(am), configData(ConfigManager::get(configKey)) {
  if (configData.empty()) {
    std::cerr
        << "FACTORY WARNING: Linked config '" << configKey
        << "' is empty. Make sure ConfigManager::load() was called before!"
        << std::endl;
  }
}
