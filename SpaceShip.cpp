#include "SpaceShip.h"

SpaceShip::SpaceShip(Location &loc) : shipLoc(loc)
{
    shipShape.setPosition(shipLoc.x, shipLoc.y);
    shipShape.setFillColor(sf::Color::Red);
    shipShape.setSize(sf::Vector2f(30, 30));
}

void SpaceShip::moveShip(int x)
{
    shipLoc.x += x;
    shipShape.setPosition(shipLoc.x, shipLoc.y);
}

void SpaceShip::setHP(int HP)
{
    shipHP = HP;
}

sf::RectangleShape SpaceShip::getShape()
{
    return shipShape;
}

Location SpaceShip::getLocation()
{
    return shipLoc;
}

int SpaceShip::getHP()
{
    return shipHP;
}

