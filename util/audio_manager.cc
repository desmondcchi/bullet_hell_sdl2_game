#include "util/audio_manager.h"

#include "SDL2/SDL_mixer.h"
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"

namespace util {

AudioManager::~AudioManager() {
  for (auto& kv : audio_map_) {
    delete kv.second;
    kv.second = nullptr;
  }
}

void AudioManager::AddAudio(absl::string_view file_path) {
  audio_map_[file_path] = Mix_LoadWAV(file_path.data());
}

void AudioManager::PlayAudio(absl::string_view name) const {
  Mix_PlayChannel(-1, audio_map_.at(name), 0);
}

}  // namespace util
