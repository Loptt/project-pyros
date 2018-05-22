#pragma once
#include "VisibleGameObject.h"

class Bullet : public VisibleGameObject
{
public:
	Bullet(int damage);
	~Bullet();

	void update(float deltaTime) override;

private:
	int speed, damage;
	float angle;
};

