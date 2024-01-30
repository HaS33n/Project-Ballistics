#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Force{
public:
    Force();
    Force(sf::Vector3f v, float val){vec = v; value = val;}
    
private:
    sf::Vector3f vec;
    float value;
};

class Projectile{
public:
    Projectile();

private:
    sf::Vector3f velocity;
    std::vector<sf::Vector3f> forces;
    float mass, surface, drag_coeff;
};