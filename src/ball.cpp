#include "ball.h"
#include <cmath>
#include <iostream>

void Ball::Update(int &scorePlayerOne, int &scorePlayerTwo)
{
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.

  handleLeftDirection(scorePlayerTwo);
  handleRightDirection(scorePlayerOne);
  handleUpDirection();
  handleDownDirection();
}

void Ball::handleLeftDirection(int &scorePlayerTwo)
{
  if (direction_x == Direction_x::kLeft)
  {
    if (head_x > 1)
    {
      head_x -= speed;
    }
    else
    {
      scorePlayerTwo++;
      direction_x = Direction_x::kRight;
    }
  }
}

void Ball::handleRightDirection(int &scorePlayerOne)
{
  if (direction_x == Direction_x::kRight)
  {
    if (head_x < grid_width - 1)
    {
      head_x += speed;
    }
    else
    {
      scorePlayerOne++;
      direction_x = Direction_x::kLeft;
    }
  }
}
void Ball::handleUpDirection()
{
  if (direction_y == Direction_y::kUp)
  {
    if (head_y > 1)
    {
      head_y -= speed;
    }
    else
    {
      direction_y = Direction_y::kDown;
    }
  }
}

void Ball::handleDownDirection()
{

  if (direction_y == Direction_y::kDown)
  {
    if (head_y < grid_height - 1)
    {
      head_y += speed;
    }
    else
    {
      direction_y = Direction_y::kUp;
    }
  }
}
