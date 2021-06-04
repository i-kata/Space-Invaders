#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_SPACESHIP_H
#define TEST_SFML_SPACESHIP_H


class SpaceShip
{
    sf::RectangleShape shipShape;
    Location shipLoc;
    int shipDir; // 1 = Left, 0 = Right

public:
    explicit SpaceShip(Location & loc);
    void moveShip(int x);
    sf::RectangleShape getShape();
    Location getLocation();
    int getShipDir();
    void changeShipDir(int dir);
};

#endif //TEST_SFML_SPACESHIP_H
