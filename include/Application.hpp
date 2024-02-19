#pragma once
#include <SFML/Graphics.hpp>
#include "Objects.hpp"

class Application{
public:
    Application();
    void run();
private:
    void updateWindow();
    void calculatePhysics();
    Simulation simulation;
    sf::RenderWindow _window;   
    sf::Event _event; 
};