#include <iostream>
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
		stateLoop();
	}

	mainWindow.close();
}

bool Game::isExiting()
{
	return gameState == Game::Exiting;
}

void Game::stateLoop()
{
	sf::Event currentEvent;

	switch (gameState)
	{
		case Game::ShowingSplash:
			showSplashScreen();
			break;

		case Game::ShowingMenu:
			showMainMenu();
			break;

		case Game::Playing:
			gameLoop();
			break;

		case Game::Exiting:
			return;
	}

	while (mainWindow.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
		{
			gameState = Game::Exiting;
		}

		break;
	}
}

void Game::gameLoop()
{
	sf::Event currentEvent;

	while (!(runningState == BackToMenu))
	{
		switch (runningState)
		{
			case BuildMode:
				performBuildMode();
				break;

			case WaveMode:
				performWaveMode();
				break;

			case Paused:
				showPausedScreen();
				break;

		}

		while (mainWindow.pollEvent(currentEvent))
		{
			if (currentEvent.type == sf::Event::Closed)
			{
				gameState = Game::Exiting;
				return;
			}
		}
	}

}

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
			gameState = Exiting;
			break;
		case MainMenu::Play:
			gameState = Playing;
			break;
	}
}

void Game::performBuildMode()
{
	PlayerBuild::BuildReturn response;
	 response = playerBuild.buildMode(mainWindow);

	 switch (response)
	 {
		case PlayerBuild::Building:
			//No change, keep building
			break;

		case PlayerBuild::Pause:
			runningState = Game::Paused;
			break;

		case PlayerBuild::StartWave:
			runningState = Game::WaveMode;
			break;

		case PlayerBuild::Exit:
			runningState = Game::BackToMenu;
			gameState = Game::Exiting;
			break;

		default:
			break;
	 }
}

void Game::performWaveMode()
{

}

void Game::showPausedScreen()
{

}

sf::RenderWindow Game::mainWindow;
Game::GameState Game::gameState = Uninitialized;
Game::RunningState Game::runningState = BuildMode;
PlayerBuild Game::playerBuild;
