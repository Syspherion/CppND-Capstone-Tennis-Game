#ifndef RACKET_H
#define RACKET_H

#include <vector>
#include "SDL.h"

class Racket {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Racket(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 10*9),
        head_y(grid_height / 2) {}

  void Update();

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  float head_x;
  float head_y;

 private:
  void UpdateHead();
  
  int grid_width;
  int grid_height;
};

#endif