#include "ball.h"
#include <cmath>
#include <iostream>

#include <iostream>
#include <chrono>
#include <ctime>
#include "config.h"

void Ball::Update(int &scorePlayerOne, int &scorePlayerTwo)
{
  handleLeftDirection(scorePlayerTwo);
  handleRightDirection(scorePlayerOne);
  handleUpDirection();
  handleDownDirection();
}

bool Ball::hitsRacketLeft()
{

  if ((head_y - racketLeft->head_y) <= Config::getRacketSize() && (head_x - racketLeft->head_x) <= 1)
  {
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << std::ctime(&end_time) << "Hit"
              << "\n";
    return true;
  }

  return false;
}

void Ball::handleLeftDirection(int &scorePlayerTwo)
{

  if (direction_x == Direction_x::kLeft)
  {

    if (hitsRacketLeft())
    {
      direction_x = Direction_x::kRight;
    }
    else if (head_x > 1)
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
