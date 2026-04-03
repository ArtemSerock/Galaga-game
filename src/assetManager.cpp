#include "assetManager.h"
#include "SDL3/SDL_render.h"
#include <iostream>
#include <string>

AssetManager::~AssetManager() {
  for (auto &pair : textures) {
    SDL_DestroyTexture(pair.second);
  }
}

AssetManager::AssetManager() {}

SDL_Texture *AssetManager::getTexture(const std::string &path,
                                      SDL_Renderer *renderer) {
  if (textures.find(path) != textures.end()) {
    return textures[path];
  }

  SDL_Texture *tex = IMG_LoadTexture(renderer, path.c_str());
  if (!tex) {
    std::cerr << "Failed to load: " << path << " Error: " << SDL_GetError()
              << std::endl;
    return nullptr;
  }

  textures[path] = tex;
  return tex;
}
