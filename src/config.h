#include <string>
#include "SDL.h"
#include <map>

#ifndef CONFIG_H
#define CONFIG_H

class Config
{
typedef std::map<std::string, std::string>MAP;

public:
   static int getRacketSize();
   static std::string getNamePlayerOne();
   static std::string getNamePlayerTwo();
   static SDL_Scancode getRacketLeftKeyUp();
   static SDL_Scancode getRacketLeftKeyDown();
   static SDL_Scancode getRacketRightKeyUp();
   static SDL_Scancode getRacketRightKeyDown();

   static std::string test;



private:
static MAP properties;
static std::string getValueFromProperties(std::string name);

};


#endif