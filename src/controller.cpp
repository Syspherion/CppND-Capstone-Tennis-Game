#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::HandleInput(bool &running, Snake &snake) const
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
        snake.direction = Snake::Direction::kUp;
        break;

      case SDLK_DOWN:
        snake.direction = Snake::Direction::kDown;
        break;

      case SDLK_SPACE:

        // TODO Add new ball
        break;
      }
    }
  }
}