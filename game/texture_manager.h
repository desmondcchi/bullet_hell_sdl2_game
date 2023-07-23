#ifndef GAME_TEXTURE_MANAGER_
#define GAME_TEXTURE_MANAGER_

#include "SDL2/SDL.h"
#include "absl/strings/string_view.h"

namespace game {

// Loads a texture given a file path to the image.
SDL_Texture* LoadTexture(SDL_Renderer* renderer, absl::string_view file_path);

}

#endif
