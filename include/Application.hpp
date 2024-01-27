#pragma once
#include <SFML/Graphics.hpp>

class Application{
public:
    Application();
    void run();
private:
    void updateWindow();

    sf::RenderWindow _window;   
    sf::Event _event; 
};