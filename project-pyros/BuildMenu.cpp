#include "BuildMenu.h"



BuildMenu::BuildMenu()
{
	MenuItem tower1Button;
	tower1Button.action = Tower1;

	MenuItem tower2Button;
	tower2Button.action = Tower2;

	MenuItem tower3Button;
	tower3Button.action = Tower3;

	MenuItem startWaveButton;
	startWaveButton.action = StartWave;

	MenuItem pauseButton;
	pauseButton.action = Pause;

	//TODO: Define button positions and actions

	menuItems.push_back(tower1Button);
	menuItems.push_back(tower2Button);
	menuItems.push_back(tower3Button);
	menuItems.push_back(startWaveButton);
	menuItems.push_back(pauseButton);
}


BuildMenu::~BuildMenu()
{
}

MasterMenu::MenuResult BuildMenu::selectFromMenu(sf::RenderWindow &window)
{
	return getMenuResponse(&window);
}
