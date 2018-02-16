//
// Created by charles on 15/02/18.
//

#include "Game.h"
#include <iostream>

Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;

void Game::start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024, 768, 32), "Pyros", sf::Style::Titlebar | sf::Style::Close);
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

                mainWindow.clear(sf::Color(255,0,0));
                mainWindow.display();

                if (currentEvent.type == sf::Event::Closed);
                {
                    gameState = Exiting;
                }

                break;

        }


    }
}

