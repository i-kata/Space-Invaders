#include <SFML/Graphics.hpp>
#include "Location.h"

#ifndef TEST_SFML_PROJECTILE_H
#define TEST_SFML_PROJECTILE_H

class Projectile
{
    sf::RectangleShape projectileShape;
    Location projectileLoc;

public:
    explicit Projectile(int x, int y);
    void shoot();
    sf::RectangleShape getShape();
    Location getLocation();
    void overboard(std::vector<Projectile> & projectiles);
};

#endif
