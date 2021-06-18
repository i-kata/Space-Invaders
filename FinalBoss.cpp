#include "FinalBoss.h"
#include <iostream>

FinalBoss::FinalBoss()
{
    finalBossShape.setSize(sf::Vector2f(200, 100));
    finalBossShape.setFillColor(sf::Color::Yellow);
    finalBossLocation.x = 200;
    finalBossLocation.y = 100;
    finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
}

void FinalBoss::fBshootNormProj(std::vector<Projectile> &fBprojectiles)
{
    for (size_t i = 0; i < 7; i++)
    {
        Projectile p(finalBossLocation.x + (70 + i*10), finalBossLocation.y + 100);
        fBprojectiles.push_back(p);
    }
}

bool FinalBoss::isOverBoard()
{
    if (finalBossLocation.x <= 400 and finalBossLocation.x >= 0 and finalBossLocation.y >= 0 and finalBossLocation.y <= 300)
        return false;
    return true;
}

void FinalBoss::fBchangePos(int x, int y)
{
    finalBossLocation.x += x;
    finalBossLocation.y += y;
    finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
}

void FinalBoss::fBmove()
{
    if (finalBossLocation.x == 0)
        dir = 0;

    if (finalBossLocation.x == 400)
        dir = 1;

    if (finalBossLocation.x > 0 and dir == 1)
        fBchangePos(-10, 0);

    if (finalBossLocation.x < 400 and dir == 0)
        fBchangePos(10, 0);
}

void FinalBoss::fBHit(int damage)
{
    finalBossHP -= damage;
}

sf::RectangleShape FinalBoss::getShape()
{
    return finalBossShape;
}

Location FinalBoss::getLocation()
{
    return finalBossLocation;
}

int FinalBoss::getHP()
{
    return finalBossHP;
}


