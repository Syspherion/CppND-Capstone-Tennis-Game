#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"
#include "racket.h"

class Ball
{
public:
  enum class Direction_x
  {
    kLeft,
    kRight
  };
  enum class Direction_y
  {
    kUp,
    kDown
  };

  Ball(int grid_width, int grid_height, Racket &racketLeft, Racket &racketRight)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2 + 1),
        racketLeft(&racketLeft),
        racketRight(&racketRight) {}

  void Update(int &scorePlayerOne, int &scorePlayerTwo);

  float speed{0.1f};
  int size{1};
  float head_x;
  float head_y;
  Racket * racketLeft;
  Racket * racketRight;

private:
  void handleLeftDirection(int &scorePlayerTwo);
  void handleRightDirection(int &scorePlayerOne);
  void handleUpDirection();
  void handleDownDirection();
  bool hitsRacketLeft();
  bool hitsRacketRight();

  Direction_x direction_x = Direction_x::kLeft;
  Direction_y direction_y = Direction_y::kUp;

  int grid_width;
  int grid_height;
};

#endif