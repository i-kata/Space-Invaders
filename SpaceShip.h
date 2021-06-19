#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_SPACESHIP_H
#define TEST_SFML_SPACESHIP_H


class SpaceShip
{
    sf::RectangleShape shipShape;
    Location shipLoc;
    int shipHP;

public:
    explicit SpaceShip(Location & loc);
    void moveShip(int x);
    sf::RectangleShape getShape();
    Location getLocation();
    void setHP(int HP);
    int getHP();
};

#endif //TEST_SFML_SPACESHIP_H
