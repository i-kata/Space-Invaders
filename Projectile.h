#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

#ifndef TEST_SFML_PROJECTILE_H
#define TEST_SFML_PROJECTILE_H

class Projectile
{
    sf::RectangleShape projectileShape;
    Location projectileLoc;

public:
    explicit Projectile(SpaceShip & ship);
    void shoot();
    sf::RectangleShape getShape();
};

#endif
