#include "Projectile.h"

Projectile::Projectile(SpaceShip & ship)
{
    projectileShape.setSize(sf::Vector2f(30, 30));
    projectileShape.setOrigin(15, 15);
    projectileShape.setFillColor(sf::Color::Blue);
    projectileShape.setPosition(ship.getLocation().x, ship.getLocation().y + 30);
}

void Projectile::shoot()
{
    while (projectileLoc.y > 0)
    {
        projectileLoc.x -= 2;
    }
}

sf::RectangleShape Projectile::getShape()
{
    return projectileShape;
}
