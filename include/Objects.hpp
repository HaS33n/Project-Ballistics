#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

struct SimData{
    std::string gun_name;
    std::string projectile_name;
    std::string s_caliber;
    
    double temperature;
    double pressure;
    std::pair<double,double> wind;

    double mass;
    double muzzle_velocity;
    double gun_elevation;
    int v_caliber; //mm

};

class Simulation{
public:
    Simulation(){};
    bool loadData();

private:

    ~Simulation(){};
};

class Force{
public:
    Force();
    Force(sf::Vector3f v, float val){vec = v; value = val;}
    //todo resultant vector calcs
private:
    sf::Vector3f vec;
    float value;
};

class Projectile{
public:
    Projectile();
    void update();
private:
    void calculateNewPosition();
    void calculateNewVelocity();
    void calculateNewForces();
    sf::Vector3f velocity, position, resultant_force;
    std::vector<Force> forces;
    float mass, surface, drag_coeff;
};