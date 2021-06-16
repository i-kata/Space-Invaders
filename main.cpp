#include <iostream>
#include <vector>
#include "SpaceShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Barier.h"
#include "Location.h"

int main()
{
    srand(time(NULL));
    bool gameRunning = true;
    sf::Event event;
    clock_t beginTime = clock();
    float duration;
    int executed = 0;
    Location shipLoc; shipLoc.x = 300; shipLoc.y = 565;
    SpaceShip ship(shipLoc);
    GameController controller;

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
        controller.controlEvents(window, event, ship, shipProjectiles);
        controller.projectilesHit(shipProjectiles, enemies);

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

        window.display();

        controller.moveEnemies(enemies, duration, executed);

        int randNum = rand() % 300;

        if (randNum < 30)
        {
            enemies[randNum].enemyShoot(enemies[randNum].getLocation(), enemyProjectiles);
        }

        controller.bariesCollision(shipProjectiles, enemyProjectiles, bariers);
        controller.moveBariers(bariers);

        duration = (clock() - beginTime) / (double) CLOCKS_PER_SEC;

    }
}
