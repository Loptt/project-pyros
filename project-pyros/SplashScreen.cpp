#include <iostream>
#include "SplashScreen.h"

void SplashScreen::show(sf::RenderWindow &window)
{
	sf::Texture background;

	if (!background.loadFromFile("Splashscreen.png"))
	{
		std::cout << "No image found" << std::endl;
		return;
	}

	sf::Sprite sprite(background);

	window.draw(sprite);
	window.display();

	sf::Event event;

	while (true)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed
				|| event.type == sf::Event::MouseButtonPressed
				|| event.type == sf::Event::Closed)
			{
				return;
			}
		}

	}
}
