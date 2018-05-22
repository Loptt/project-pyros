#pragma once
#include "Button.h"
#include "MasterMenu.h"
#include <list>

class BuildMenu : public MasterMenu
{
public:
	BuildMenu();
	~BuildMenu();

	MenuResult selectFromMenu(sf::RenderWindow &window);

private:
	
};

