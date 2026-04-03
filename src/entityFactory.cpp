#include "entityFactory.h"
#include <fstream>

EntityFactory::EntityFactory(AssetManager &am, const std::string &jsonPath)
    : manager(am) {

  std::ifstream file(jsonPath);
  if (!file.is_open()) {

    std::cerr << "CRITICAL: Could not open config at: "
              << std::filesystem::absolute(jsonPath) << std::endl;
    return;
  }
  file.seekg(0, std::ios::end);
  if (file.tellg() == 0) {
    std::cerr << "FACTORY: Error - File is EMPTY: " << jsonPath << std::endl;
    return;
  }
file.seekg(0, std::ios::beg);
  try {
    file >> configData;
} catch (const nlohmann::json::parse_error& e) {
    std::cerr << "JSON Parse Error: " << e.what() << std::endl;
}


  try {
    file >> configData;
    std::cout << "FACTORY: Config loaded successfully from " << jsonPath
              << std::endl;
  } catch (const nlohmann::json::parse_error &e) {
    std::cerr << "FACTORY: JSON Parse Error: " << e.what() << std::endl;
  }
}
