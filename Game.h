//
// Created by charles on 15/02/18.
//

#ifndef PROJECT_PYROS_GAME_H
#define PROJECT_PYROS_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
    static void start();

private:
    static bool isExiting();
    static void stateLoop();
    static void gameLoop();

    static void showSplashScreen();
    static void showMainMenu();

    enum GameState {Uninitialized, ShowingSplash, ShowingMenu, Playing,
                    Exiting};

    enum RunningState {BuildMode, WaveMode, Paused, BackToMenu};

    static GameState gameState;
    static RunningState runningState;

    static sf::RenderWindow mainWindow;
};

#endif //PROJECT_PYROS_GAME_H
