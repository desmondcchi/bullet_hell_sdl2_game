#include "game/texture_manager.h"

#include <iostream>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "absl/strings/string_view.h"

namespace game {

SDL_Texture* LoadTexture(SDL_Renderer* renderer, absl::string_view file_path) {
  std::cout << file_path.data() << "\n";
  SDL_Surface* temp_surface = IMG_Load(file_path.data());
  if (temp_surface) {
    std::cout << "No error\n";
  } else {
    std::cout << "Error\n";
    std::cout << SDL_GetError();
    std::cout << IMG_GetError();
  }
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
  SDL_FreeSurface(temp_surface);

  return texture;
}

}  // namespace game
