#include "Barier.h"

Barier::Barier()
{
    barierShape.setSize(sf::Vector2f(150, 30));
    barierShape.setFillColor(sf::Color::Yellow);
}

void Barier::setPosition(float x, float y)
{
    barierShape.setPosition(x, y);
}

sf::RectangleShape Barier::getShape()
{
    return barierShape;
}

Location Barier::getLocation()
{
    return barerLoc;
}

int Barier::getLife()
{
    return barierLife;
}