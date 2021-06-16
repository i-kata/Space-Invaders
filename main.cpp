#include <iostream>
#include <vector>
#include "SpaceShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Barier.h"
#include "Location.h"
#include "FinalBoss.h"

int main()
{
    srand(time(NULL));
    bool mainWindow = false;
    bool firstStage = true;
    bool bossStage = false;
    sf::Event event;
    clock_t beginTime = clock();
    float duration;
    int executed = 0;
    Location shipLoc; shipLoc.x = 300; shipLoc.y = 565;
    SpaceShip ship(shipLoc);
    GameController controller;
    FinalBoss finalBoss;

    std::vector<Projectile> shipProjectiles;
    std::vector<Projectile> enemyProjectiles;
    std::vector<Enemy> enemies;
    std::vector<Barier> bariers;

    controller.spawnEnemiesnR(enemies);
    controller.spawnBariers(bariers);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Space Invaders");
    window.setFramerateLimit(30);

    while (window.isOpen())
    {
        window.clear();

        window.draw(ship.getShape());

        if (not shipProjectiles.empty())
        {
            for (auto & p : shipProjectiles)
            {
                window.draw(p.getShape());
                p.shootShip();
                p.overboard(shipProjectiles);
            }
        }

        if (not bariers.empty())
        {
            for (auto & b : bariers)
                window.draw(b.getShape());
        }

        if (not enemyProjectiles.empty())
        {
            for (auto & ep : enemyProjectiles)
            {
                window.draw(ep.getShape());
                ep.shootEnemy();
                ep.overboard(enemyProjectiles);
            }
        }

        if (not enemies.empty())
        {
            for (auto & e : enemies)
            {
                window.draw(e.getShape());
            }
        }

        if (not enemies.empty())
        {
            int randNum = rand() % (enemies.size() * 10);
            if (randNum < enemies.size())
            {
                enemies[randNum].enemyShoot(enemies[randNum].getLocation(), enemyProjectiles);
            }
        }

        controller.controlEvents(window, event, ship, shipProjectiles);
        controller.projectilesHit(shipProjectiles, enemies);
        controller.bariesCollision(shipProjectiles, enemyProjectiles, bariers);
        controller.spaceshipHit(ship, enemyProjectiles, firstStage);
        controller.moveBariers(bariers);
        controller.moveEnemies(enemies, duration, executed);

        if (enemies.empty())
        {
            window.draw(finalBoss.getShape());
            controller.finalBossHit(finalBoss, shipProjectiles);
            finalBoss.fBmoveRandom();
        }

        duration = (clock() - beginTime) / (double) CLOCKS_PER_SEC;

        window.display();
    }
}
