#ifndef ENTITIES_ENTITY_H_
#define ENTITIES_ENTITY_H_

#include "SDL2/SDL.h"

namespace entities {

class Entity {
 public:
  virtual ~Entity() = default;

  SDL_FPoint GetPosition() const;
  float GetWidth() const;
  float GetHeight() const;
  virtual void Update() = 0;
  virtual void Render() = 0;
  virtual int GenerateID() const = 0;
  virtual SDL_FRect* GetRect() = 0;

 protected:
  SDL_Renderer* renderer_;
  SDL_FPoint position_;
  float width_ = 0.0f;
  float height_ = 0.0f;
  float speed_ = 0.0f;
  SDL_FRect rect_;
  int id_;
};

}  // namespace entities

#endif
