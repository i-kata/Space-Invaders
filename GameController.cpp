#include "GameController.h"
#include "Projectile.h"

void GameController::controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship, std::vector<Projectile> & projectiles)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    ship.moveShip(-15);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    ship.moveShip(15);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    Projectile p(ship.getLocation().x, ship.getLocation().y - 30);
                    projectiles.push_back(p);
                }
                break;

            default:
                break;
        }
    }
}