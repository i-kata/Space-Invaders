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

void FinalBoss::fBmove()
{
    int randNum = rand() % 300;

    if (randNum >= 20 and randNum <= 30 and not isOverBoard())
    {
        finalBossLocation.x += 20;
        finalBossLocation.y += 20;
        finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
    }

    if (randNum >= 10 and randNum <= 15 and not isOverBoard())
    {
        finalBossLocation.x -= 20;
        finalBossLocation.y -= 20;
        finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
    }

    if (randNum >= 100 and randNum <= 115 and not isOverBoard())
    {
        finalBossLocation.x -= 10;
        finalBossLocation.y += 30;
        finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
    }

    if (randNum >= 200 and randNum <= 230 and not isOverBoard())
    {
        finalBossLocation.x += 10;
        finalBossLocation.y -= 30;
        finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
    }
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


