#pragma once
#include <string>
#include "VisibleGameObject.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void add(std::string name, VisibleGameObject *gameObject);
	void remove(std::string name);
	int getObjectCount() const;
	VisibleGameObject *get(std::string name) const;

	void drawAll(sf::RenderWindow &window);
	void updateAll(float timeDelta);
	
private:
	std::map<std::string, VisibleGameObject*> gameObjects;

	struct gameObjectDeallocator
	{
		void operator()(const std::pair<std::string, VisibleGameObject*> &p) const
		{
			delete p.second;
		}
	};
};