#include "GameController.h"
#include "Projectile.h"
#include "SpaceShip.h"
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
                    if (ship.getShipDir() == 0)
                        ship.moveShip(-15);

                    ship.moveShip(-15);
                    ship.changeShipDir(1);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (ship.getShipDir() == 1)
                        ship.moveShip(15);

                    ship.moveShip(15);
                    ship.changeShipDir(0);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    Projectile p(ship.getLocation().x + 15, ship.getLocation().y - 30);
                    projectiles.push_back(p);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    ship.moveShip(-15);
                    Projectile p(ship.getLocation().x + 15, ship.getLocation().y - 30);
                    projectiles.push_back(p);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    ship.moveShip(15);
                    Projectile p(ship.getLocation().x + 15, ship.getLocation().y - 30);
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
    for (size_t enemy = 0; enemy < enemies.size(); enemy++)
    {
        for (size_t proj = 0; proj < projectiles.size(); proj++)
        {
            if (projectiles[proj].getLocation().x >= enemies[enemy].getLocation().x - 12 and
                projectiles[proj].getLocation().x <= enemies[enemy].getLocation().x + 42 and
                projectiles[proj].getLocation().y <= enemies[enemy].getLocation().y + 12 and
                projectiles[proj].getLocation().y >= enemies[enemy].getLocation().y - 12)
            {
                enemies[enemy].gotHit();
                if (enemies[enemy].getHealth() == 0)
                {
                    enemies.erase(enemies.begin() + enemy);
                    projectiles.erase(projectiles.begin() + proj);
                }

                else
                {
                    projectiles.erase(projectiles.begin() + proj);
                }
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
    }
}

void GameController::spawnEnemiesnR(std::vector<Enemy> &enemies)
{
    for (int row = 2; row >= 0; row--)
    {
        for (size_t i = 0; i < 10; i++)
        {
            Location newEnemyLoc;
            newEnemyLoc.x = 60 + i * 50;
            newEnemyLoc.y = 30 + row * 60;

            Enemy newEnemy(newEnemyLoc);
            newEnemy.enemyEstHealth(4);

            enemies.push_back(newEnemy);
        }
    }
}

void GameController::moveEnemiesForward(std::vector<Enemy> &enemies)
{
    Location moveLoc;
    moveLoc.x = 0;
    moveLoc.y = 30;

    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(moveLoc);
    }
}

void GameController::moveEnemiesLeft(std::vector<Enemy> &enemies)
{
    Location moveLoc;
    moveLoc.x = -30;
    moveLoc.y = 30;

    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(moveLoc);
    }
}

void GameController::moveEnemiesRight(std::vector<Enemy> &enemies)
{
    Location moveLoc;
    moveLoc.x = 30;
    moveLoc.y = 30;

    for (size_t i = 0; i < enemies.size(); i++)
    {
        enemies[i].move(moveLoc);
    }
}

void GameController::moveEnemies(std::vector<Enemy> &enemies, float duration, int & executed)
{
    if (duration >= 4.95 and duration <= 5.05 and executed < 1)
    {
        moveEnemiesForward(enemies);
        executed++;
    }

    if (duration >= 7.45 and duration <= 7.55 and executed < 2)
    {
        moveEnemiesLeft(enemies);
        executed++;
    }

    if (duration >= 9.95 and duration <= 10.05 and executed < 3)
    {
        moveEnemiesRight(enemies);
        executed++;
    }

    if (duration >= 11.95 and duration <= 12.05 and executed < 4)
    {
        moveEnemiesForward(enemies);
        executed++;
    }

    if (duration >= 15.45 and duration <= 15.55 and executed < 5)
    {
        moveEnemiesRight(enemies);
        executed++;
    }

    if (duration >= 17.95 and duration <= 18.05 and executed < 6)
    {
        moveEnemiesLeft(enemies);
        executed++;
    }
}


