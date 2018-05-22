#pragma once
#include "VisibleGameObject.h"
#include "MachineTower.h"

class Tower : public VisibleGameObject
{
public:
	Tower();
	~Tower();

	virtual void shoot() = 0;

protected:
	int speed, damage, range;
};

