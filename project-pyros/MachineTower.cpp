#include "MachineTower.h"



MachineTower::MachineTower()
{
	load("some/file.png");

	speed = 100;
	damage = 25;
	range = 50;
}


MachineTower::~MachineTower()
{
}

void MachineTower::update(float elapsedTime)
{
	//TODO: Add animations and actions
}

void MachineTower::shoot()
{
	//TODO: Add implementation for shooting
}
