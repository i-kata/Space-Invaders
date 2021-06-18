#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_SPACESHIP_H
#define TEST_SFML_SPACESHIP_H


class SpaceShip
{
    sf::RectangleShape shipShape;
    Location shipLoc;

public:
    explicit SpaceShip(Location & loc);
    void moveShip(int x);
    sf::RectangleShape getShape();
    Location getLocation();
    void setTexture(sf::Texture &shipTexture);
};

#endif //TEST_SFML_SPACESHIP_H
