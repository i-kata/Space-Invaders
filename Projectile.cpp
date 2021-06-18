#include "Projectile.h"
#include <memory>
#include <iostream>

Projectile::Projectile(int x, int y)
{
    projectileShape.setSize(sf::Vector2f(10, 30));
    projectileLoc.x = x;
    projectileLoc.y = y;
    projectileShape.setPosition(projectileLoc.x, projectileLoc.y);
}

void Projectile::shootShip()
{
    projectileLoc.y -= 15;
    projectileShape.setPosition(projectileLoc.x, projectileLoc.y);
}

void Projectile::shootEnemy()
{
    projectileLoc.y += 15;
    projectileShape.setPosition(projectileLoc.x, projectileLoc.y);
}

void Projectile::overboard(std::vector<Projectile> &projectiles)
{
    for (size_t p = 0; p < projectiles.size(); p++)
    {
        if (projectiles[p].getLocation().y < 0 or projectiles[p].getLocation().y > 600)
            projectiles.erase(projectiles.begin() + p);
    }
}

sf::RectangleShape Projectile::getShape()
{
    return projectileShape;
}

Location Projectile::getLocation()
{
    return projectileLoc;
}

