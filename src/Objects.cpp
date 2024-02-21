#include "../include/Objects.hpp"
#include <iostream>

double degToRad(const double& deg){
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

	sf::Vector3d gravity;
	gravity.x = 0;
	gravity.y = -mass * 9.81;
	gravity.z = 0;
	forces.push_back(gravity);

	sf::Vector3d drag;
	drag.x = -(velocity.x * velocity.x * 1.2) / 2 * drag_coeff * area;
	drag.y = -(velocity.y * velocity.y * 1.2) / 2 * drag_coeff * area;
	drag.z = -(velocity.z * velocity.z * 1.2) / 2 * drag_coeff * area;
	forces.push_back(drag);

}

void Projectile::_calculateResultantForce(){
	for(auto &it : forces)
		resultant_force += it;
}

sf::Vector3d Projectile::_calculateAcceleration(){
	return {resultant_force.x / mass, resultant_force.y / mass, resultant_force.z / mass};
}

void Projectile::_calculatePosition(const double & t){
	sf::Vector3d a = _calculateAcceleration();

	double x = (velocity.x * t) + (a.x *t *t / 2);
	double y = (velocity.y * t) + (a.y *t *t / 2);
	double z = (velocity.z * t) + (a.z *t *t / 2);

	position += {x,y,z};
}

void Projectile::_calculateVelocity(const double & t){
	sf::Vector3d a = _calculateAcceleration();

	double x = a.x * t;
	double y = a.y * t;
	double z = a.z * t;

	velocity += {x,y,z};
}

void Projectile::_updateForces(){
	sf::Vector3d drag;
	drag.x = -(velocity.x * velocity.x * 1.2) / 2 * drag_coeff * area;
	drag.y = -(velocity.y * velocity.y * 1.2) / 2 * drag_coeff * area;
	drag.z = -(velocity.z * velocity.z * 1.2) / 2 * drag_coeff * area;
	forces[1] = drag;
}

void Projectile::makeCalculations(const double& t){
	_calculateResultantForce();
	_calculatePosition(t);
	_calculateVelocity(t);
	_updateForces();
}

Simulation::Simulation(){

}

bool Simulation::loadData(){
	mINI::INIFile inifile("simulation_data.ini");
	mINI::INIStructure ini;
	inifile.read(ini);

	_data.step = stod(ini["config"]["simulation_time_step"]);

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

	_projectile.init(_data.muzzle_velocity, _data.gun_elevation, _data.mass, _data.v_caliber);


	output.open("calculated_ballistic_curve.bcf", std::ios::app | std::ios::trunc);
	if(!output.good())
		return false;

    return true;
}

void Simulation::savePoint(){
	output<<_projectile.getPosition().x<<","
		<<_projectile.getPosition().y<<","
		<<_projectile.getPosition().z<<"/"
		<<_projectile.getVelocity().x<<","
		<<_projectile.getVelocity().y<<","
		<<_projectile.getVelocity().z<<"/"
		<<_projectile.getAngle()<<"\n";
}

void Simulation::runSimulation(){
	output<<_data.step<<"\n";
	savePoint();
	long double count = 0;

	do{
		_projectile.makeCalculations(_data.step);
		savePoint();
		count++;

		if(count>30000)
			break;
		
	}while(_projectile.getPosition().y > 0);
	output.close();
}

