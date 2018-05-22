#include "PlayerBuild.h"

PlayerBuild::PlayerBuild()
{
	gold = 0;
}


PlayerBuild::~PlayerBuild()
{
}

PlayerBuild::BuildReturn PlayerBuild::buildMode(sf::RenderWindow &window)
{
	MasterMenu::MenuResult result = buildMenu.selectFromMenu(window);
	int towerCost = 0;

	switch (result)
	{
		case MasterMenu::Pause:
			return PlayerBuild::Pause;
			break;

		case MasterMenu::MachineTower:
			towerCost = 10;

			if (validateMove(towerCost, window))
			{
				Tower *tower = new MachineTower();
				towerManager.add(tower);
			}
			break;

		case MasterMenu::Tower2:
			towerCost = 20;

			if (validateMove(towerCost, window))
			{
				Tower *tower = new MachineTower();
				towerManager.add(tower);
			}

			break;

		case MasterMenu::Tower3:
			towerCost = 30;

			if (validateMove(towerCost, window))
			{
				Tower *tower = new MachineTower();
				towerManager.add(tower);
			}
			break;

		case MasterMenu::StartWave:
			return PlayerBuild::StartWave;
			break;

		case MasterMenu::Exit:
			return PlayerBuild::Exit;
			break;

		default:

			break;
	}

	return PlayerBuild::Building;
}

bool PlayerBuild::validateMove(int towerCost, sf::RenderWindow & window)
{
	if (gold >= towerCost) //if enough money
	{
		if (selectPosition(window)) //if space is valid
		{
			//TODO: Add tower to towerManager
			//Tower built
			gold -= towerCost;
			return true;
		}
		else
		{
			//TODO: Build interface to send message
			//Send message not valid position
			DialogMenu dialog;
		}
	}
	else
	{
		//TODO: Implement interface to send message
		//Send message not enough money
		DialogMenu dialog;
	}

	return false;
}

bool PlayerBuild::selectPosition(sf::RenderWindow & window)
{
	return false;
}

