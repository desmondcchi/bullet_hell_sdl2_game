#ifndef ENTITIES_ENTITY_H_
#define ENTITIES_ENTITY_H_

#include "SDL2/SDL.h"

namespace entities {

class Entity {
 public:
  float GetXPos() const;
  float GetYPos() const;
  virtual void Update() = 0;
  virtual void Render() = 0;
  virtual int GenerateID() const = 0;
  virtual SDL_Rect* GetRect() = 0;

 protected:
  SDL_Renderer* renderer_;
  int x_pos_;
  int y_pos_;
  int width_;
  int height_;
  int speed_;
  SDL_Rect rect_;
  int id_;
};

}  // namespace entities

#endif
