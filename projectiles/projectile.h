#ifndef PROJECTILES_PROJECTILE_H_
#define PROJECTILES_PROJECTILE_H_

namespace projectiles {

class Projectile {
 public:
	virtual void HandleMovement() = 0;
  virtual void Update() = 0;
  virtual void Render() = 0;

 protected:
	SDL_Renderer* renderer_;
	int width_;
	int height_;
	int x_pos_;
	int y_pos_;
	int speed_;
};

}  // namespace projectiles

#endif
