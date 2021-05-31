#include <SFML/Graphics.hpp>
#include "Location.h"
#include "Projectile.h"

#ifndef TEST_SFML_ENEMY_H
#define TEST_SFML_ENEMY_H


class Enemy
{
    sf::RectangleShape enemyShape;
    Location enemyLoc;
    float health = 4;
    float defense;

public:
    Enemy(Location & loc);
    void move(Location & loc);
    void attack();
    Location getLocation();
    float getHealth();
    sf::RectangleShape getShape();
};


#endif //TEST_SFML_ENEMY_H
