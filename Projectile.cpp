#include "Projectile.h"

Projectile::Projectile(int x, int y)
{
    projectileShape.setSize(sf::Vector2f(10, 30));
    projectileShape.setFillColor(sf::Color::Blue);
    projectileLoc.x = x;
    projectileLoc.y = y;
    projectileShape.setPosition(projectileLoc.x, projectileLoc.y);
}

void Projectile::shoot()
{
    projectileLoc.y -= 2;
    projectileShape.setPosition(projectileLoc.x, projectileLoc.y);
}

void Projectile::overboard(std::vector<Projectile> &projectiles)
{
    for (size_t p = 0; p < projectiles.size(); p++)
    {
        if (projectiles[p].getLocation().y < 0)
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
