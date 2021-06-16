#ifndef TEST_SFML_BARIER_H
#define TEST_SFML_BARIER_H

#include <SFML/Graphics.hpp>
#include "Location.h"

class Barier
{
    sf::RectangleShape barierShape;
    Location barierLoc;
    int barierDir = 1; // 1 = Left, 0 = Right
public:
    Barier();
    Location getLocation();
    void setPosition(int x, int y);
    sf::RectangleShape getShape();
    int getDirection();
    void setDirection(int dir);
};


#endif //TEST_SFML_BARIER_H
