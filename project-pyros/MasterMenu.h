#pragma once
#include "Button.h"
#include <list>

class MasterMenu
{
public:
	MasterMenu();
	~MasterMenu();

	enum MenuResult { Nothing, Exit, Play, Pause, Instructions, MachineTower, Tower2, Tower3, StartWave };

	struct MenuItem
	{
		Button button;
		MenuResult action;
	};

	virtual MenuResult show(sf::RenderWindow &window);

protected:
	MenuResult getMenuResponse(sf::RenderWindow *window);
	MenuResult handleClick(sf::Vector2i mousePos);
	std::list<MenuItem> menuItems;
};

