#include "Barier.h"

Barier::Barier()
{
    barierShape.setSize(sf::Vector2f(100, 30));
    barierShape.setFillColor(sf::Color::Yellow);
}


void Barier::setPosition(int x, int y)
{
    barierShape.setPosition(x, y);
    barierLoc.x = x;
    barierLoc.y = y;
}

sf::RectangleShape Barier::getShape()
{
    return barierShape;
}

Location Barier::getLocation()
{
    return barierLoc;
}

int Barier::getDirection()
{
    return barierDir;
}

void Barier::setDirection(int dir)
{
    barierDir = dir;
}
