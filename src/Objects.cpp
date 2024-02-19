#include "../include/Objects.hpp"
#include <iostream>

bool Simulation::loadData(){
	mINI::INIFile inifile("simulation_data.ini");
	mINI::INIStructure ini;
	inifile.read(ini);

	data.gun_name = ini["projectile"]["gun_name"];
	data.projectile_name = ini["projectile"]["projectile_name"];
	data.s_caliber = ini["projectile"]["caliber"];

	data.temperature = stod(ini["enviroment"]["temperature"]);
	data.pressure = stod(ini["enviroment"]["pressure"]);

	std::string wnd = ini["enviroment"]["wind"];
	data.wind.first = stod(wnd.substr(0,wnd.find('/')));
	data.wind.second = stod(wnd.substr(wnd.find('/')+1));

	data.mass = stod(ini["projectile"]["mass"]);
	data.muzzle_velocity = stod(ini["projectile"]["muzzle_velocity"]);
	data.gun_elevation = stod(ini["projectile"]["gun_elevation"]);

	std::string cal = ini["projectile"]["caliber"];
	cal = cal.substr(0,cal.find('/'));
	data.v_caliber = stoi(cal);

    return true;
}