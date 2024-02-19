#include "../include/Application.hpp"

Application::Application(){
	//create and configure new window
    _window.create(sf::VideoMode(800,600),"Project Ballistics");
    _window.setFramerateLimit(75);

	//load simulation data
	if(!simulation.loadData())
		exit(EXIT_FAILURE);
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