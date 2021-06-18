#ifndef TEST_SFML_FINALBOSS_H
#define TEST_SFML_FINALBOSS_H

#include <SFML/Graphics.hpp>
#include "Location.h"
#include "Projectile.h"

class FinalBoss
{
    sf::RectangleShape finalBossShape;
    Location finalBossLocation;
    int finalBossHP = 30;
    int dir = 1; // 1 = Left, 0 = Right

public:
    FinalBoss();
    void fBmove();
    bool isOverBoard();
    void fBchangePos(int x, int y);
    void fBHit(int damage);
    void fBshootNormProj(std::vector<Projectile> &fBprojectiles);
    sf::RectangleShape getShape();
    Location getLocation();
    int getHP();
};


#endif //TEST_SFML_FINALBOSS_H
