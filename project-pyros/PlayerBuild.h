#pragma once
#include "GameObjectManager.h"
class PlayerBuild
{
public:
	PlayerBuild();
	~PlayerBuild();

	int getGold() { return gold; }
	void setGold(int gold) { this->gold = gold; }

private:
	GameObjectManager towerManager;
	int gold;
};

