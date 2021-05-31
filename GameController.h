#include <SFML/Graphics.hpp>
#include "SpaceShip.h"

#ifndef TEST_SFML_GAMECONTROLLER_H
#define TEST_SFML_GAMECONTROLLER_H

class GameController
{
public:
    void controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship);
};

#endif
