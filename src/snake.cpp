#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update() {
  
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

}

void Snake::UpdateHead() {
  
  if(direction == Direction::kUp){
    if(head_y > 0){
      head_y -= speed;
    }
    return;
  }

    if(direction == Direction::kDown){
    if(head_y < grid_height-1){
      head_y += speed;
    }
    return;
  }

    if(direction == Direction::kLeft){
    if(head_x > 0){
      head_x -= speed;
    }
    return;
  }

    if(direction == Direction::kRight){
    if(head_x < grid_width-1){
      head_x += speed;
    }
    return;
  }
  
}