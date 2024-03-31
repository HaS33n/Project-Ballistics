#include <fstream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Objects.hpp"

class Gauge : public sf::Drawable{ //to powinna być klasa szablonowa
public:
    Gauge(const double& src);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    const double& source;
    sf::Text content;
};

class Visualisation{
public:
    Visualisation(sf::RenderWindow& _tw);
    void generateFrame();
private:
    //fnc

    sf::RenderWindow& _target_window;
    std::vector<Gauge> gauges;
    sf::CircleShape _projectile;
};