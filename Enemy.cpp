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

void Enemy::move(Location loc)
{
    enemyLoc.x += loc.x;
    enemyLoc.y += loc.y;
    enemyShape.setPosition(enemyLoc.x, enemyLoc.y);
}

Location Enemy::getLocation()
{
    return enemyLoc;
}

sf::RectangleShape Enemy::getShape()
{
    return enemyShape;
}

int Enemy::getHealth()
{
    return health;
}

void Enemy::gotHit()
{
    health = health - 2;
}

void Enemy::enemyEstHealth(int hlth)
{
    health = hlth;
}

void Enemy::enemyShoot(Location enemyShootingLoc, std::vector<Projectile> &enemyProjectiles)
{
    Projectile enemyProjectile(enemyShootingLoc.x, enemyShootingLoc.y);
    enemyProjectiles.push_back(enemyProjectile);
}

