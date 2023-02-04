#include "ball.h"
#include "config.h"
#include <cmath>
#include <iostream>

void Ball::Update(int &scorePlayerOne, int &scorePlayerTwo)
{
  handleLeftDirection(scorePlayerTwo);
  handleRightDirection(scorePlayerOne);
  handleUpDirection();
  handleDownDirection();
}

bool Ball::hitsRacketLeft()
{
  if (head_y >= racketLeft->getHeadY() && head_y <=racketLeft->getHeadY()+Config::getRacketSize() && (head_x - racketLeft->getHeadX()) <= 1)
  {
    return true;
  }
  return false;
}

bool Ball::hitsRacketRight()
{
  if (head_y >= racketRight->getHeadY() && head_y <=racketRight->getHeadY()+Config::getRacketSize() && (racketRight->getHeadX() - head_x) <= 1)
  {
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
    if (hitsRacketRight())
    {
      direction_x = Direction_x::kLeft;
    }
    else if (head_x < grid_width - 1)
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
