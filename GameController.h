#include <SFML/Graphics.hpp>
#include <vector>
#include "SpaceShip.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Barier.h"
#include "FinalBoss.h"

#ifndef TEST_SFML_GAMECONTROLLER_H
#define TEST_SFML_GAMECONTROLLER_H

enum gameDifficulty {EASY, NORMAL, HARD};

class GameController
{
    gameDifficulty gameDifficulty;

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
    void bariesCollision(std::vector<Projectile> & shipProjectiles, std::vector<Projectile> & enemyProjectiles, std::vector<Projectile> &finalBossProjectiles, std::vector<Barier> & bariers);
    void spaceshipHit(SpaceShip & spaceShip, std::vector<Projectile> & enemyProjectiles, bool &gameRunning);
    void finalBossHit(FinalBoss &finalBoss, std::vector<Projectile> &shipProjectiles);
    void controlEventsGF(sf::RenderWindow & window, sf::Event & event, bool & gameRunning);
    void setGame(enum gameDifficulty gd, std::vector<Enemy> & enemies, SpaceShip &ship);
    enum gameDifficulty getGD();
    void isGameRunning(SpaceShip &ship, FinalBoss &fb, sf::RenderWindow &window, sf::Text & text);
};

#endif
