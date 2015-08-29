#ifndef GAME_OBJECT_FACTORY_H
#define GAME_OBJECT_FACTORY_H


#include <string>
#include <map>
#include "GameObject.h"
#include <iostream>

class BaseCreator
{
public:
	virtual GameObject* CreateGameObject() const = 0;
	virtual ~BaseCreator() {}
};


class GameObjectFactory
{
public:

	static GameObjectFactory* Instance();

	bool RegisterType(std::string typeID, BaseCreator* pCreator);
	GameObject* Create(std::string typeID);

private:
	GameObjectFactory();
	static GameObjectFactory* s_instance;
	std::map<std::string, BaseCreator*> m_creators;
};

#endif