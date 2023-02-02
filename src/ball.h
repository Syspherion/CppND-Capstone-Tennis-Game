#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"

class Ball {
 public:
  enum class Direction_x { kLeft, kRight };
  enum class Direction_y { kUp, kDown };

  Ball(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2+1) {}

  void Update();

  bool RacketCell(int x, int y);



  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();

  Direction_x direction_x = Direction_x::kLeft;
  Direction_y direction_y = Direction_y::kUp;

  int grid_width;
  int grid_height;
};

#endif