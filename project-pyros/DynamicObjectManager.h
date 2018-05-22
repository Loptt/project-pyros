#pragma once
#include <vector>
#include "VisibleGameObject.h"

template<class T>
class DynamicObjectManager
{
public:
	DynamicObjectManager();
	~DynamicObjectManager();

	void add(T);
	void remove(int pos);

	T get(int pos);

	int getObjectCount();

private:
	std::vector<T> dynamicObjects;
};
