#include "GameController.h"
#include "Projectile.h"
#include <iostream>

void GameController::controlEvents(sf::RenderWindow & window, sf::Event & event, SpaceShip & ship, std::vector<Projectile> & projectiles)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    ship.moveShip(-15);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    ship.moveShip(15);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    Projectile p(ship.getLocation().x, ship.getLocation().y - 30);
                    projectiles.push_back(p);
                }
                break;

            default:
                break;
        }
    }
}

void GameController::projectilesHit(std::vector<Projectile> &projectiles, std::vector<Enemy> & enemies)
{
    for (size_t proj = 0; proj < projectiles.size(); proj++)
    {
        for (size_t enemy = 0; enemy < enemies.size(); enemy++)
        {
            if (projectiles[proj].getLocation().x >= enemies[enemy].getLocation().x - 2 and
                projectiles[proj].getLocation().x <= enemies[enemy].getLocation().x + 32 and
                projectiles[proj].getLocation().y <= enemies[enemy].getLocation().y + 2 and
                projectiles[proj].getLocation().y >= enemies[enemy].getLocation().y - 2)
            {
                std::cout << "HIT!" << std::endl;
                enemies.erase(enemies.begin() + enemy);
            }
        }
    }
}

void GameController::spawnEnemies(std::vector<Enemy> &enemies)
{
    Location firstEnemyLoc;
    firstEnemyLoc.x = rand() % 570 + 30;
    firstEnemyLoc.y = rand() % 400 + 30;
    Enemy firstEnemy(firstEnemyLoc);
    enemies.push_back(firstEnemy);

    for (int i = 0; i < 10; i++)
    {
        bool locationEstablished = false;
        Location enemyLoc;
        enemyLoc.x = rand() % 570 + 30;
        enemyLoc.y = rand() % 400 + 30;

        while (locationEstablished == false)
        {
            for (size_t j = 0; j < enemies.size(); j++)
            {
                if (enemyLoc.x != enemies[j].getLocation().x and enemyLoc.y != enemies[j].getLocation().y)
                {
                    Enemy newEnemy(enemyLoc);
                    enemies.push_back(newEnemy);
                    locationEstablished = true;
                }
            }
        }
        std::cout << i << " " << std::endl;
    }
}