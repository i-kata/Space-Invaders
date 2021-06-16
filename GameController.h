#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Barier.h"

#ifndef TEST_SFML_GAMECONTROLLER_H
#define TEST_SFML_GAMECONTROLLER_H

class GameController
{
public:
    void controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship, std::vector<Projectile> & projectiles);
    void projectilesHit(std::vector<Projectile> & projectiles, std::vector<Enemy> & enemies);
    void spawnEnemies(std::vector<Enemy> & enemies);
    void spawnEnemiesnR(std::vector<Enemy> & enemies);
    void moveEnemiesForward(std::vector<Enemy> & enemies);
    void moveEnemiesLeft(std::vector<Enemy> & enemies);
    void moveEnemiesRight(std::vector<Enemy> & enemies);
    void moveEnemies(std::vector<Enemy> & enemies, float duration, int & executed);
    void spawnBariers(std::vector<Barier> & bariers);
    void moveBariers(std::vector<Barier> & bariers);
    void bariesCollision(std::vector<Projectile> & shipProjectiles, std::vector<Projectile> & enemyProjectiles,std::vector<Barier> & bariers);
};

#endif
