#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "PlayerBuild.h"

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
	static void performBuildMode();
	static void performWaveMode();
	static void showPausedScreen();

	enum GameState {
		Uninitialized, ShowingSplash, ShowingMenu, Playing,
		Exiting
	};

	enum RunningState { BuildMode, WaveMode, Paused, BackToMenu };

	static GameState gameState;
	static RunningState runningState;

	static sf::RenderWindow mainWindow;

	static PlayerBuild playerBuild;
};

