#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "renderer.h"
#include "racket.h"
#include "ball.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScorePlayerOne() const;
  int GetScorePlayerTwo() const;
  int GetSize() const;

 private:
  Racket racket;
  Ball ball;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int scorePlayerOne{0};
  int scorePlayerTwo{0};

  void Update();
};

#endif