#ifndef GAME_AUDIO_MANAGER_H_
#define GAME_AUDIO_MANAGER_H_

#include "SDL2/SDL_mixer.h"
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"

namespace game {

class AudioManager {
 public:
  ~AudioManager();

  // Add audio to hash map collection, which stores each audio file's sound.
  void AddAudio(absl::string_view file_path);

  // Plays a audio file's sound.
  void PlayAudio(absl::string_view name) const;

 private:
  absl::flat_hash_map<std::string, Mix_Chunk*> audio_map_;
};

}  // namespace game

#endif
