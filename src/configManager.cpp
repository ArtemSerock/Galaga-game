#include "configManager.h"

std::unordered_map<std::string, nlohmann::json> ConfigManager::configs;
nlohmann::json ConfigManager::emptyJson = nlohmann::json::object();

bool ConfigManager::load(const std::string& key, const std::string& path) {

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "FILE NOT FOUND!" << std::endl;
        return false;
    }
}

const nlohmann::json& ConfigManager::get(const std::string& key) {
    auto it = configs.find(key);
    if (it != configs.end()) {
        return it->second;
    }
    std::cerr << "[ConfigManager] Config '" << key << "' not found!" << std::endl;
    return emptyJson;
}

bool ConfigManager::has(const std::string& key) {
    return configs.find(key) != configs.end();
}
