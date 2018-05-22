#include "MasterMenu.h"


MasterMenu::MasterMenu()
{
}


MasterMenu::~MasterMenu()
{
}

MasterMenu::MenuResult MasterMenu::show(sf::RenderWindow & window)
{
	return getMenuResponse(&window);
}

MasterMenu::MenuResult MasterMenu::getMenuResponse(sf::RenderWindow * window)
{
	sf::Event menuEvent;

	while (true)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			return handleClick(sf::Mouse::getPosition(*window));
		}
		while (window->pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}

MasterMenu::MenuResult MasterMenu::handleClick(sf::Vector2i mousePos)
{
	std::list<MenuItem>::iterator it;

	for (it = menuItems.begin(); it != menuItems.end(); ++it)
	{
		if ((*it).button.isButtonClicked(mousePos))
		{
			return (*it).action;
		}
	}

	return Nothing;
}
