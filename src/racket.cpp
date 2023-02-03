#include "racket.h"
#include <cmath>
#include <iostream>
#include "config.h"

void Racket::Update()
{

  if (direction == keyUp)
  {
    if (head_y > 0)
    {
      head_y -= speed;
    }
    return;
  }

  if (direction == keyDown)
  {
    if (head_y < grid_height - Config::getRacketSize())
    {
      head_y += speed;
    }
    return;
  }
}
