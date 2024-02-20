#include "../include/Objects.hpp"
#include <iostream>

double degToRad(double deg){
    return (deg * (M_PI / 180));
}

void Projectile::init(double v0, double phi, double m, double cal){
	angle = phi;
    mass = m;
    drag_coeff = 0.4;

	double cl = cal * 0.001;
	area = M_PI * (cl/2) * (cl/2);

	position = {0,0,0};

	velocity.x = v0 * cos(degToRad(angle));
	velocity.y = v0 * sin(degToRad(angle));
	velocity.z = 0;

	sf::Vector3d drag;
	drag.x = -(velocity.x * velocity.x * 1.2) / 2 * drag_coeff * area;
	drag.y = -(velocity.y * velocity.y * 1.2) / 2 * drag_coeff * area;
	drag.z = -(velocity.z * velocity.z * 1.2) / 2 * drag_coeff * area;
	forces.push_back(drag);

	sf::Vector3d gravity;
	gravity.x = 0;
	gravity.y = -mass * 9.81;
	gravity.z = 0;
	forces.push_back(gravity);

}

Simulation::Simulation(){

}

bool Simulation::loadData(){
	mINI::INIFile inifile("simulation_data.ini");
	mINI::INIStructure ini;
	inifile.read(ini);

	_data.gun_name = ini["projectile"]["gun_name"];
	_data.projectile_name = ini["projectile"]["projectile_name"];
	_data.s_caliber = ini["projectile"]["caliber"];

	_data.temperature = stod(ini["enviroment"]["temperature"]);
	_data.pressure = stod(ini["enviroment"]["pressure"]);

	std::string wnd = ini["enviroment"]["wind"];
	_data.wind.first = stod(wnd.substr(0,wnd.find('/')));
	_data.wind.second = stod(wnd.substr(wnd.find('/')+1));

	_data.mass = stod(ini["projectile"]["mass"]);
	_data.muzzle_velocity = stod(ini["projectile"]["muzzle_velocity"]);
	_data.gun_elevation = stod(ini["projectile"]["gun_elevation"]);

	std::string cal = ini["projectile"]["caliber"];
	cal = cal.substr(0,cal.find('/'));
	_data.v_caliber = stod(cal);

    return true;
}

void Simulation::update(const sf::Time& time){

}
