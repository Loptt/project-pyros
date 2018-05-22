#pragma once
#include "Button.h"
#include "MasterMenu.h"
#include <list>

class MainMenu : public MasterMenu
{
public:
	MainMenu();
	~MainMenu();

	MenuResult show(sf::RenderWindow &window) override;

private:

};
