#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <string>
#include "SDL.h"
#include "racket.h"
#include "ball.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Racket const racket, Ball const ball);
  void UpdateWindowTitle(int scorePlayerOne, int scorePlayerTwo, int fps);

 private:
  std::string BuildWindowTitle(int scorePlayerOne, int scorePlayerTwo, int fps);
  void RenderRacket(Racket const racket);
  void RenderBall(Ball const ball);
  
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif