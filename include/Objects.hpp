#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Projectile{
public:
    Projectile();

private:
    sf::Vector3f velocity;
    std::vector<sf::Vector3f> forces;
    float mass, surface, drag_coeff;
};