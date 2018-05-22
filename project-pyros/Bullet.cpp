#include "Bullet.h"

Bullet::Bullet(int damage)
{
	this->damage = damage;
	speed = 100;

	load("some/image.png");
}

Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{

}
