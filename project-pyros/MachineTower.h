#pragma once
#include "Tower.h"

class MachineTower : public Tower
{
public:
	MachineTower();
	~MachineTower();

	void update(float elapsedTime) override;

	void shoot() override;

private:

};

