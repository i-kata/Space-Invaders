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
                        ship.moveShip(-30);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {

                    ship.moveShip(30);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                {
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
            if (projectiles[proj].getLocation().x >= enemies[enemy].getLocation().x - 10 and
                projectiles[proj].getLocation().x <= enemies[enemy].getLocation().x + 40 and
                projectiles[proj].getLocation().y <= enemies[enemy].getLocation().y + 30)
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

void GameController::spawnBariers(std::vector<Barier> &bariers)
{
    Barier barier1;
    barier1.setPosition(80, 510);

    Barier barier2;
    barier2.setPosition(250, 510);

    Barier barier3;
    barier3.setPosition(420, 510);

    bariers.push_back(barier1);
    bariers.push_back(barier2);
    bariers.push_back(barier3);
}

void GameController::moveBariers(std::vector<Barier> & bariers)
{
    if (bariers[0].getLocation().x > 0 and bariers[0].getDirection() == 1)
    {
        for (size_t i = 0; i < bariers.size(); i++)
        {
            bariers[i].setPosition(bariers[i].getLocation().x - 1, 510);
        }

        if (bariers[0].getLocation().x == 0)
        {
            for (auto &b : bariers)
                b.setDirection(0);
        }
    }

    if (bariers[2].getLocation().x < 500 and bariers[0].getDirection() == 0)
    {
        for (size_t i = 0; i < bariers.size(); i++)
        {
            bariers[i].setPosition(bariers[i].getLocation().x + 1, 510);
        }

        if (bariers[2].getLocation().x == 500)
        {
            bariers[0].setDirection(1);
        }
    }
}

void GameController::bariesCollision(std::vector<Projectile> & shipProjectiles, std::vector<Projectile> & enemyProjectiles, std::vector<Projectile> &finalBossProjectiles, std::vector<Barier> & bariers)
{
    for (size_t barier = 0; barier < bariers.size(); barier++)
    {
        for (size_t sprojectile = 0; sprojectile < shipProjectiles.size(); sprojectile++)
        {
            if (shipProjectiles[sprojectile].getLocation().y >= bariers[barier].getLocation().y and
                shipProjectiles[sprojectile].getLocation().y <= bariers[barier].getLocation().y + 30 and
                shipProjectiles[sprojectile].getLocation().x >= bariers[barier].getLocation().x and
                shipProjectiles[sprojectile].getLocation().x <= bariers[barier].getLocation().x + 100)
            {
                shipProjectiles.erase(shipProjectiles.begin() + sprojectile);
            }
        }
    }

    for (size_t barier = 0; barier < bariers.size(); barier++)
    {
        for (size_t eprojectile = 0; eprojectile < enemyProjectiles.size(); eprojectile++)
        {
            if (enemyProjectiles[eprojectile].getLocation().y + 30 >= bariers[barier].getLocation().y and
                enemyProjectiles[eprojectile].getLocation().x >= bariers[barier].getLocation().x and
                enemyProjectiles[eprojectile].getLocation().x <= bariers[barier].getLocation().x + 100)
            {
                enemyProjectiles.erase(enemyProjectiles.begin() + eprojectile);
            }
        }
    }

    if (not finalBossProjectiles.empty())
    {
        for (size_t barier = 0; barier < bariers.size(); barier++)
        {
            for (size_t fBprojectile = 0; fBprojectile < finalBossProjectiles.size(); fBprojectile++)
            {
                if (finalBossProjectiles[fBprojectile].getLocation().y + 30 >= bariers[barier].getLocation().y and
                    finalBossProjectiles[fBprojectile].getLocation().x >= bariers[barier].getLocation().x and
                    finalBossProjectiles[fBprojectile].getLocation().x <= bariers[barier].getLocation().x + 100)
                {
                    finalBossProjectiles.erase(finalBossProjectiles.begin() + fBprojectile);
                }
            }
        }
    }
}

void GameController::spaceshipHit(SpaceShip &spaceShip, std::vector<Projectile> &enemyProjectiles, bool &gameRunning)
{
    for (size_t p = 0; p < enemyProjectiles.size(); p++)
    {
        if (enemyProjectiles[p].getLocation().y + 30 >= spaceShip.getLocation().y and
            enemyProjectiles[p].getLocation().x >= spaceShip.getLocation().x and
            enemyProjectiles[p].getLocation().x <= spaceShip.getLocation().x + 30)
        {
            gameRunning = false;
            enemyProjectiles.erase(enemyProjectiles.begin() + p);
        }
    }
}

void GameController::finalBossHit(FinalBoss &finalBoss, std::vector<Projectile> &shipProjectiles)
{
    for (size_t p = 0; p < shipProjectiles.size(); p++)
    {
        if (shipProjectiles[p].getLocation().y <= finalBoss.getLocation().y + 100 and
            shipProjectiles[p].getLocation().x >= finalBoss.getLocation().x and
            shipProjectiles[p].getLocation().x <= finalBoss.getLocation().x + 200)
        {
            finalBoss.fBHit(2);
            shipProjectiles.erase(shipProjectiles.begin() + p);
        }
    }
}


