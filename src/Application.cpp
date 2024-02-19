#include "../include/Application.hpp"

Application::Application(){
	//create and configure new window
    _window.create(sf::VideoMode(800,600),"Project Ballistics");
    _window.setFramerateLimit(75);

	//load simulation data
	mINI::INIFile inifile("simulation_data.ini");
	mINI::INIStructure ini;
	inifile.read(ini);
	SimData data;

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
}

void Application::run(){
    while (_window.isOpen()){
		while (_window.pollEvent(_event)) {
			switch (_event.type)
			{
			case sf::Event::Closed:
				_window.close();
				break;
			default:
				break;
			}
		}
		updateWindow();
	}
}

void Application::updateWindow(){
    _window.clear();
    //draw TODO
    _window.display();
}