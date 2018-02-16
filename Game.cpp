//
// Created by charles on 15/02/18.
//

#include "Game.h"
#include <string>

void Game::start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024, 768, 32), "Pyros");
    gameState = Playing;

    while (!isExiting())
    {
        gameLoop();
    }

    mainWindow.close();
}

bool Game::isExiting()
{
    return gameState == Exiting;
}

void Game::gameLoop()
{
    sf::Event currentEvent;

    while (mainWindow.pollEvent(currentEvent))
    {
        switch (gameState)
        {
            case Playing:


        }
    }
}
