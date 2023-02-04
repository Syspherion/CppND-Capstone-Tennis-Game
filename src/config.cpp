#include "config.h"
#include <sstream>
#include <fstream>
#include <iostream>

std::map<std::string, std::string> Config::properties = []
{
    std::cout << "Start init properties\n";
    std::map<std::string, std::string> properties;
    std::ifstream infile("config.properties");
    if (infile.is_open())
    {
        std::string line;

        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            std::string name, value;
            if (!(iss >> name >> value))
            {
                std::cout << "Error while reading values from file"
                          << "\n";
                break;
            } // error
            std::cout << "Read values from file: " << name << " / " << value << "\n";
            properties.insert(std::pair<std::string, std::string>(name, value));
        }
    }
    else
    {
        std::cout << "Properties file not found!\n";
    }

    return properties;
}();

std::string Config::getValueFromProperties(std::string name)
{
    MAP::const_iterator pos = properties.find(name);
    if (pos == properties.end())
    {
        return "";
    }
    else
    {
        return pos->second;
    }
}

int Config::getRacketSize()
{
    std::string size = getValueFromProperties("RacketSize");
    if (size == "")
    {
        return 5;
    }
    else
    {
        return std::stoi(size);
    }
}

std::string Config::getNamePlayerOne()
{
    std::string namePlayerOne = getValueFromProperties("NamePlayerOne");
    if (namePlayerOne == "")
    {
        return "Manuel";
    }
    else
    {
        return namePlayerOne;
    }
}

std::string Config::getNamePlayerTwo()
{
        std::string namePlayerOne = getValueFromProperties("NamePlayerTwo");
    if (namePlayerOne == "")
    {
        return "Melanie";
    }
    else
    {
        return namePlayerOne;
    }
}

SDL_Scancode Config::getRacketLeftKeyUp()
{
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
