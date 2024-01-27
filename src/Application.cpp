#include "../include/Application.hpp"

Application::Application(){
    _window.create(sf::VideoMode(400,400),"Project Ballistics");
    _window.setFramerateLimit(75);
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