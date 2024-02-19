#pragma once
#include <SFML/Graphics.hpp>
#include "ini.h"
#include "Objects.hpp"

class Application{
public:
    Application();
    void run();
private:
    void updateWindow();
    void calculatePhysics();
    sf::RenderWindow _window;   
    sf::Event _event; 
};