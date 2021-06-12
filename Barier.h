#ifndef TEST_SFML_BARIER_H
#define TEST_SFML_BARIER_H

#include <SFML/Graphics.hpp>
#include "Location.h"

class Barier
{
    sf::RectangleShape barierShape;
    Location barerLoc;
    int barierLife;
public:
    Barier();
    Location getLocation();
    void destroyed(std::vector<Barier> & bariers);
    int getLife();
    void setPosition(float x, float y);
    sf::RectangleShape getShape();
};


#endif //TEST_SFML_BARIER_H
