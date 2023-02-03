#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "config.h"

void Controller::HandleInput(bool &running, Racket &racketLeft, Racket &racketRight) const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN)
    {

      if (e.key.keysym.scancode == Config::getRacketLeftKeyUp())
      {
        racketLeft.direction = Config::getRacketLeftKeyUp();
        return;
      }

      if (e.key.keysym.scancode == Config::getRacketLeftKeyDown())
      {
        racketLeft.direction = Config::getRacketLeftKeyDown();
        return;
      }

      if (e.key.keysym.scancode == Config::getRacketRightKeyUp())
      {
        racketRight.direction = Config::getRacketRightKeyUp();
        return;
      }

      if (e.key.keysym.scancode == Config::getRacketRightKeyDown())
      {
        racketRight.direction = Config::getRacketRightKeyDown();
        return;
      }
    }
  }
}