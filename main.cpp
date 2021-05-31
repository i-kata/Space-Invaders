#include <iostream>
#include <vector>
#include "SpaceShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Location.h"

int main()
{
    Location shipLoc; shipLoc.x = 300; shipLoc.y = 585;
    SpaceShip ship(shipLoc);
    GameController controller;
    std::vector<Projectile> projectiles;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Space Invaders");
    window.setFramerateLimit(30);

    sf::Event event;

    while (window.isOpen())
    {
        controller.controlEvents(window, event, ship, projectiles);

        window.clear();
        window.draw(ship.getShape());
        for (auto & p : projectiles)
        {
            window.draw(p.getShape());
            p.shoot();
            p.overboard(projectiles);
        }
        window.display();
    }
}
