#include "MainMenu.h"
#include <chrono>
#include <thread>

MainMenu::MainMenu()
{
	MenuItem playButton;
	playButton.action = Play;
	//TODO: Add button positioning and size

	MenuItem instructionsButton;
	instructionsButton.action = Instructions;
	//TODO: Add button positioning and size

	MenuItem exitButton;
	exitButton.action = Exit;
	//TODO: Add button positioning and size

	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);
	menuItems.push_back(instructionsButton);
}

MainMenu::~MainMenu()
{
}

MasterMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
	sf::Texture texture;

	if (!texture.loadFromFile("images/Mainmenu.png"))
	{
		return Nothing;
	}

	sf::Sprite sprite(texture);

	window.draw(sprite);
	window.display();

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	return getMenuResponse(&window);
}
