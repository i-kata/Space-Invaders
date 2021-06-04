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

    while (window.isOpen())
    {
        controller.controlEvents(window, event, ship, shipProjectiles);
        controller.projectilesHit(shipProjectiles, enemies);

        window.clear();
        window.draw(ship.getShape());

        if (shipProjectiles.size() > 0)
        {
            for (auto & p : shipProjectiles)
            {
                window.draw(p.getShape());
                p.shoot();
                p.overboard(shipProjectiles);
            }
        }

        if (enemies.size() > 0)
        {
            for (auto & e : enemies)
            {
                window.draw(e.getShape());
            }
        }

        window.display();
    }
}
