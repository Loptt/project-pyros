#pragma once
#include "DynamicObjectManager.h"
#include "Tower.h"
#include "BuildMenu.h"
#include "DialogMenu.h"

class PlayerBuild
{
public:
	PlayerBuild();
	~PlayerBuild();

	enum BuildReturn {Pause, StartWave, Building, Exit};

	int getGold() { return gold; }
	void setGold(int gold) { this->gold = gold; }

	BuildReturn buildMode(sf::RenderWindow &window);
	bool validateMove(int towerCost, sf::RenderWindow &window);

private:

	bool selectPosition(sf::RenderWindow &window);

	DynamicObjectManager<Tower*> towerManager;
	BuildMenu buildMenu;
	int gold;
};
