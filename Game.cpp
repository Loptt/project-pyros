//
// Created by charles on 15/02/18.
//


#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::start()
{
    if (gameState != Uninitialized)
        return;

    mainWindow.create(sf::VideoMode(1024, 768, 32), "Pyros", sf::Style::Titlebar | sf::Style::Close);
    gameState = Game::ShowingSplash;

    while (!isExiting())
    {
        gameLoop();
    }

    mainWindow.close();
}

bool Game::isExiting()
{
    return gameState == Game::Exiting;
}

void Game::gameLoop()
{
    sf::Event currentEvent;
    while (mainWindow.pollEvent(currentEvent))
    {
        switch (gameState)
        {
            case Game::ShowingSplash:
                showSplashScreen();
                break;

            case Game::ShowingMenu:
                break;

            case Game::Playing:

                mainWindow.clear(sf::Color(255,0,0));
                mainWindow.display();

                if (currentEvent.type == sf::Event::Closed)
                {
                    gameState = Game::Exiting;
                }

                break;
        }
    }
}

Game::GameState Game::gameState = Uninitialized;

void Game::showSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(mainWindow);
    gameState = Game::ShowingMenu;
}

void Game::showMainMenu()
{
    MainMenu menu;
    MainMenu::MenuResult result = menu.show(mainWindow);

    switch (result)
    {
        case MainMenu::Exit:
            gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            gameState = Game::Playing;
            break;
    }
}

sf::RenderWindow Game::mainWindow;