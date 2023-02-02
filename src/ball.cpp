#include "ball.h"
#include <cmath>
#include <iostream>

void Ball::Update()
{

  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)}; // Capture the head's cell after updating.
}

void Ball::UpdateHead()
{
  if (direction_x == Direction_x::kLeft)
  {
    if (head_x > 1)
    {
      head_x -= speed;
    }
    else
    {
      direction_x = Direction_x::kRight;
    }
  }

  if (direction_x == Direction_x::kRight)
  {
    if (head_x < grid_width - 1)
    {
      head_x += speed;
    }
    else
    {
      direction_x = Direction_x::kLeft;
    }
  }

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

// Inefficient method to check if cell is occupied by snake.
bool Ball::RacketCell(int x, int y)
{
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}