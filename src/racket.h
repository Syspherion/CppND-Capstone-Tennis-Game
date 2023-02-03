#ifndef RACKET_H
#define RACKET_H

#include <vector>
#include "SDL.h"

class Racket
{
public:
  Racket(int grid_width, int grid_height, int pos_x, SDL_Keycode keyUp, SDL_Keycode keyDown)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(pos_x),
        head_y(grid_height / 2 - 3),
        keyUp(keyUp),
        keyDown(keyDown) {}

  void Update();

  SDL_Keycode direction;
  SDL_Keycode keyUp;
  SDL_Keycode keyDown;

  float speed{0.1f};
  int size{1};
  float head_x;
  float head_y;

private:
  int grid_width;
  int grid_height;
};

#endif