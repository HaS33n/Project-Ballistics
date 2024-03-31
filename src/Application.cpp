#include "../include/Application.hpp"

Application::Application() : _visualisation(_window){
	std::cout<<"loading simulation data... \n";
	//load simulation data
	if(!_simulation.loadData()){
		std::cout<<"loading failure! \n";
		exit(EXIT_FAILURE);
	}
		

	std::cout<<"Simulation data loaded \n";
}

void Application::run(){
	std::cout<<"Calculating projectile path, this might take a while...\n";
	sf::Clock* calc_clk = new sf::Clock;

	_simulation.runSimulation();

	std::cout<<"Simulation completed, time taken: " 
		<< calc_clk->getElapsedTime().asSeconds() << " seconds \n";
	delete calc_clk;
	std::cout<<"Starting Visualisation... \n";


    _window.create(sf::VideoMode(800,600),"Project Ballistics!");
    _window.setFramerateLimit(75);

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
	_visualisation.generateFrame();
    _window.display();
}