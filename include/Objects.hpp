#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include "ini.h"

namespace sf{
    typedef sf::Vector3<double> Vector3d;
}

double degToRad(const double& deg);

struct SimData{
    double step;

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

struct PathPoint
{
   sf::Vector3d pos;
   sf::Vector3d velocity;
   double angle;
};


class Projectile{
public:
    Projectile(){};
    void init(double v0, double phi, double m, double cal); //phi = angle
    const sf::Vector3d& getPosition() {return position;}
    const sf::Vector3d& getVelocity() {return velocity;}
    const double& getAngle() {return angle;}

    void makeCalculations(const double& t);
private:
    void _calculateResultantForce();
    sf::Vector3d _calculateAcceleration();
    void _calculatePosition(const double& t);
    void _calculateVelocity(const double& t);
    void _updateForces();

    sf::Vector3d velocity, position, resultant_force;
    double angle;
    std::vector<sf::Vector3d> forces;
    double mass, area, drag_coeff;
};

class Simulation{
public:
    Simulation();
    bool loadData();
    void runSimulation();

private:
    void savePoint();

    SimData _data;
    Projectile _projectile;
    std::fstream output;
};