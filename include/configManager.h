#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

/**
 * @brief Менеджер конфигураций
 *
 * скачивает JSON файлы и ищет в них данные
 */
class ConfigManager {
public:
  static bool load(const std::string &key, const std::string &path);

  static const nlohmann::json &get(const std::string &key);

  static bool has(const std::string &key);

private:
  static std::unordered_map<std::string, nlohmann::json> configs;
  static nlohmann::json emptyJson;
};

#endif
