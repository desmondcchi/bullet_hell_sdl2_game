#ifndef ENTITIES_ENTITY_H_
#define ENTITIES_ENTITY_H_

#include "SDL2/SDL.h"

namespace entities {

class Entity {
 public:
  virtual ~Entity() = default;

  enum Direction { kNone, kUp, kDown, kLeft, kRight };

  SDL_FPoint GetPosition() const;
  float GetWidth() const;
  float GetHeight() const;
  virtual void Move(Direction dir) = 0;
  virtual void Update() = 0;
  virtual void Render() = 0;

 protected:
  SDL_Renderer* renderer_;
  SDL_FPoint position_;
  float width_ = 0.0f;
  float height_ = 0.0f;
  float speed_ = 0.0f;
  SDL_Texture* texture_;
  SDL_Rect src_rect_;
  SDL_FRect dest_rect_;
};

}  // namespace entities

#endif
