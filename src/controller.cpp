#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "racket.h"

void Controller::HandleInput(bool &running, Racket &racket) const
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
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        racket.direction = Racket::Direction::kUp;
        break;

      case SDLK_DOWN:
        racket.direction = Racket::Direction::kDown;
        break;

      case SDLK_SPACE:

        // TODO Add new ball
        break;
      }
    }
  }
}