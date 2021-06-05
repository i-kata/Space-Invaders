#include <iostream>
#include <vector>
#include "SpaceShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Enemy.h"
#include "Location.h"

int main()
{
    Location shipLoc; shipLoc.x = 300; shipLoc.y = 565;
    SpaceShip ship(shipLoc);
    GameController controller;
    std::vector<Projectile> shipProjectiles;
    std::vector<Projectile> enemyProjectiles;
    std::vector<Enemy> enemies;

    controller.spawnEnemiesnR(enemies);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Space Invaders");
    window.setFramerateLimit(30);

    sf::Event event;

    clock_t beginTime = clock();
    float duration;
    int executed = 0;

    while (window.isOpen())
    {
        controller.controlEvents(window, event, ship, shipProjectiles);
        controller.projectilesHit(shipProjectiles, enemies);

        window.clear();
        window.draw(ship.getShape());

        if (!shipProjectiles.empty())
        {
            for (auto & p : shipProjectiles)
            {
                window.draw(p.getShape());
                p.shootShip();
                p.overboard(shipProjectiles);
            }
        }

        if (!enemyProjectiles.empty())
        {
            for (auto & ep : enemyProjectiles)
            {
                window.draw(ep.getShape());
                ep.shootEnemy();
                ep.overboard(enemyProjectiles);
            }
        }

        int randNum = rand() % 30;
        enemies[randNum].enemyShoot(enemies[randNum].getLocation(), enemyProjectiles);

        if (!enemies.empty())
        {
            for (auto & e : enemies)
            {
                window.draw(e.getShape());
            }
        }

        window.display();

        controller.moveEnemies(enemies, duration, executed);

        duration = (clock() - beginTime) / (float) CLOCKS_PER_SEC;
    }
}
