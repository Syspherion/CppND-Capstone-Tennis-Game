#include "config.h"


int Config::getRacketSize()
{
    return 5;
}

std::string Config::getNamePlayerOne()
{
    return "Manuel";
}

std::string Config::getNamePlayerTwo()
{
    return "Melanie";
}

SDL_Scancode Config::getRacketLeftKeyUp(){
    return SDL_SCANCODE_W;
}

SDL_Scancode Config::getRacketLeftKeyDown()
{
    return SDL_SCANCODE_S;
}

SDL_Scancode Config::getRacketRightKeyUp()
{
    return SDL_SCANCODE_UP;
}

SDL_Scancode Config::getRacketRightKeyDown()
{
    return SDL_SCANCODE_DOWN;
}
