#include "../include/VisualUtils.hpp"

void Gauge::draw(sf::RenderTarget & target, sf::RenderStates states) const{
    target.draw(content,states);
}

Gauge::Gauge(const double& src) : source(src){

}

Visualisation::Visualisation(sf::RenderWindow & _tw) : _target_window(_tw){
    _projectile.setFillColor(sf::Color::Red);
    _projectile.setRadius(5);
    _projectile.setPosition(10,10);
}

void Visualisation::generateFrame(){
    _target_window.draw(_projectile);
}
