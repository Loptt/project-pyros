#include "DynamicObjectManager.h"

template<class T>
DynamicObjectManager::DynamicObjectManager()
{

}

template<class T>
DynamicObjectManager::~DynamicObjectManager()
{
	dynamicObjects.clear();
}

template<class T>
void DynamicObjectManager<T>::add(T object)
{
	dynamicObjects.push_back(object);
}

template<class T>
void DynamicObjectManager<T>::remove(int pos)
{
	dynamicObjects.erase(pos);
}

template<class T>
T DynamicObjectManager<T>::get(int pos)
{
	return dynamicObjects.at(pos);
}

template<class T>
int DynamicObjectManager<T>::getObjectCount()
{
	return dynamicObjects.size();
}
