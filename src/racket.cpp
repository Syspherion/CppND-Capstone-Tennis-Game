#include "racket.h"
#include <cmath>
#include <iostream>
#include "config.h"

void Racket::Update() {
  
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

}

void Racket::UpdateHead() {
  
  if(direction == Direction::kUp){
    if(head_y > 0){
      head_y -= speed;
    }
    return;
  }

    if(direction == Direction::kDown){
    if(head_y < grid_height-Config::getRacketSize()){
      head_y += speed;
    }
    return;
  }

}