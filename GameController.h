#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.h"
#include "Projectile.h"
#include "Enemy.h"

#ifndef TEST_SFML_GAMECONTROLLER_H
#define TEST_SFML_GAMECONTROLLER_H

class GameController
{
public:
    void controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship, std::vector<Projectile> & projectiles);
    void projectilesHit(std::vector<Projectile> & projectiles, std::vector<Enemy> & enemies);
    void spawnEnemies(std::vector<Enemy> & enemies);
};

#endif
