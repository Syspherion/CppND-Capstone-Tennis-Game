#include "renderer.h"
#include "config.h"
#include <iostream>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow(BuildWindowTitle(0, 0, 0).c_str(), SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Racket const racket, Ball const ball)
{
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  Renderer::RenderBall(ball);
  Renderer::RenderRacket(racket);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::RenderRacket(Racket const racket)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  block.x = static_cast<int>(racket.head_x) * block.w;
  block.y = static_cast<int>(racket.head_y) * block.h;

  for (size_t i = 0; i < Config::getRacketSize(); i++)
  {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
    SDL_RenderFillRect(sdl_renderer, &block);

    block.y = block.y + block.h;
  }
}

void Renderer::RenderBall(Ball const ball)
{
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Render ball
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = static_cast<int>(ball.head_x) * block.w;
  block.y = static_cast<int>(ball.head_y) * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);
}

void Renderer::UpdateWindowTitle(int scorePlayerOne, int scorePlayerTwo, int fps)
{
  std::string title = BuildWindowTitle(scorePlayerOne, scorePlayerTwo, fps);
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

std::string Renderer::BuildWindowTitle(int scorePlayerOne, int scorePlayerTwo, int fps)
{
  return "Tennis " + Config::getNamePlayerOne() + ": " + std::to_string(scorePlayerOne) + " / " + Config::getNamePlayerTwo() + ": " + std::to_string(scorePlayerTwo) + " FPS: " + std::to_string(fps);
}
