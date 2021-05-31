#include <iostream>
#include "SpaceShip.h"
#include "GameController.h"
#include "Projectile.h"
#include "Location.h"

int main()
{
    Location shipLoc; shipLoc.x = 300; shipLoc.y = 570;
    SpaceShip ship(shipLoc);
    GameController controller;
    Projectile projectile(ship);

    sf::RenderWindow window(sf::VideoMode(600, 600), "Space Invaders");
    window.setFramerateLimit(60);

    sf::Event event;

    while (window.isOpen())
    {
        controller.controlEvents(window, event, ship);

        window.clear();
        window.draw(ship.getShape());
        window.display();
    }
}
