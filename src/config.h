#include <string>
#include "SDL.h"

#ifndef CONFIG_H
#define CONFIG_H

class Config
{
public:
   static int getRacketSize();
   static std::string getNamePlayerOne();
   static std::string getNamePlayerTwo();
   static SDL_Scancode getRacketLeftKeyUp();
   static SDL_Scancode getRacketLeftKeyDown();
   static SDL_Scancode getRacketRightKeyUp();
   static SDL_Scancode getRacketRightKeyDown();
};

#endif