#include "GameController.h"

void GameController::controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship)
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
                break;

            default:
                break;
        }
    }
}