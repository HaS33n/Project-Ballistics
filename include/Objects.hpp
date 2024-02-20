#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "ini.h"

namespace sf{
    typedef sf::Vector3<double> Vector3d;
}

double degToRad(double deg);

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
    double v_caliber; //mm

};

class Projectile{
public:
    Projectile();
    void init(double v0, double phi, double m, double cal); //phi = angle
private:
    void calculateNewPosition();
    void calculateNewVelocity();
    void calculateNewForces();

    sf::Vector3d velocity, position, resultant_force;
    double angle;
    std::vector<sf::Vector3d> forces;
    double mass, area, drag_coeff;
};

class Simulation{
public:
    Simulation();
    bool loadData();
    void update(const sf::Time& time);
private:
    SimData _data;
    Projectile _projectile;
};