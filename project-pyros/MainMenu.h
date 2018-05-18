#pragma once
#include "Button.h"
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play, Instructions };

	struct MenuItem
	{
		Button button;
		MenuResult action;
	};

	MenuResult show(sf::RenderWindow &window);

private:

	MenuResult getMenuResponse(sf::RenderWindow *window);
	MenuResult handleClick(sf::Vector2i mousePos);
	std::list<MenuItem> menuItems;
};
