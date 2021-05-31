#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Location &loc)
{
    enemyLoc.x = loc.x;
    enemyLoc.y = loc.y;
    enemyShape.setSize(sf::Vector2f(30, 30));
    enemyShape.setPosition(enemyLoc.x, enemyLoc.y);
    enemyShape.setFillColor(sf::Color::Cyan);
}

void Enemy::move(Location & loc)
{
    enemyLoc.x = loc.x;
    enemyLoc.y = loc.y;
    enemyShape.setPosition(enemyLoc.x, enemyLoc.y);
}

float Enemy::getHealth()
{
    return health;
}

Location Enemy::getLocation()
{
    return enemyLoc;
}

sf::RectangleShape Enemy::getShape()
{
    return enemyShape;
}

