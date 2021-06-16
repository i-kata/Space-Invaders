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

void FinalBoss::fBmoveRandom()
{
    int randNum = rand() % 1000;

    if (randNum >= 50 and randNum <= 65)
    {
        finalBossLocation.x = rand() % 400;
        finalBossLocation.y = rand() % 200;

        finalBossShape.setPosition(finalBossLocation.x, finalBossLocation.y);
    }
}

void FinalBoss::fBshootNormProj(std::vector<Projectile> &fBprojectiles)
{
    for (size_t i = 0; i < 7; i++)
    {
        Projectile p(finalBossLocation.x + (70 + i*10), finalBossLocation.y + 100);
        fBprojectiles.push_back(p);
    }

    for (auto &p : fBprojectiles)
        p.shootEnemy();
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
