#include "GameObjectFactory.h"


GameObjectFactory* GameObjectFactory::s_instance = 0;

GameObjectFactory* GameObjectFactory::Instance()
{
	if (s_instance == 0)
	{
		s_instance = new GameObjectFactory();
	}
	return s_instance;
}

GameObjectFactory::GameObjectFactory()
{
}

bool GameObjectFactory::RegisterType(std::string typeID, BaseCreator* pCreator)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
	// if the type is already registered, do nothing
	if (it != m_creators.end())
	{
		delete pCreator;
		return false;
	}
	m_creators[typeID] = pCreator;
	return true;
}

GameObject* GameObjectFactory::Create(std::string typeID)
{
	std::map<std::string, BaseCreator*>::iterator it =
		m_creators.find(typeID);
	if (it == m_creators.end())
	{
		std::cout << "could not find type: " << typeID << "\n";
		return NULL;
	}
	BaseCreator* pCreator = (*it).second;
	return pCreator->CreateGameObject();
}