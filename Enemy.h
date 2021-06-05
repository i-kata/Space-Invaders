#include <SFML/Graphics.hpp>
#include "Location.h"
#include "Projectile.h"

#ifndef TEST_SFML_ENEMY_H
#define TEST_SFML_ENEMY_H


class Enemy
{
    sf::RectangleShape enemyShape;
    Location enemyLoc;
    int health;

public:
    explicit Enemy(Location & loc);
    void move(Location loc);
    Location getLocation();
    sf::RectangleShape getShape();
    int getHealth();
    void gotHit();
    void enemyEstHealth(int hlth);
    void enemyShoot(Location enemyShootingLoc, std::vector<Projectile> & enemyProjectiles);
};


#endif //TEST_SFML_ENEMY_H
