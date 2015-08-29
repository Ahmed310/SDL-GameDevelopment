#include "StateParser.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"
#include "Game.h"
#include <stdlib.h>
#include <fstream>
#include <vector>

bool StateParser::ParseState( 
	const char *stateFile, 
	std::string stateID, 
	std::vector<GameObject *> *pObjects, 
	std::vector<std::string> *pTextureIDs)
{
	std::cout << " that the id you just passed " + stateID  << "\n";
	// create the XML document
	rapidxml::xml_document<> doc;


	std::ifstream theFile(stateFile);
	std::vector<char> buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// get the root element

	rapidxml::xml_node<>* root_node = 0;
	rapidxml::xml_node<>* state_root = 0;
	root_node = doc.first_node();

	std::cout << root_node->name() << "\n";

	for (rapidxml::xml_node<>* e = root_node->first_node(); e !=
		NULL; e = e->next_sibling())
	{
		std::cout << e->name() << "\n";
		if (e->name() == stateID)
		{
			state_root = e;
		}
	}

	// pre declare the texture root
	rapidxml::xml_node<>* texture_root = 0;
	// get the root of the texture elements

	for (rapidxml::xml_node<>* e = state_root->first_node(); e !=
		NULL; e = e->next_sibling())
	{
		std::cout << e->name() << "\n";
		if (e->name() == std::string("TEXTURES"))
		{
			texture_root = e;
		}
	}

	// now parse the textures
	ParseTextures(texture_root, pTextureIDs);
	// pre declare the object root node

	rapidxml::xml_node<>* object_root = 0;

	for (rapidxml::xml_node<>* e = state_root->first_node("OBJECTS"); e !=
		NULL; e = e->next_sibling())
	{
		std::cout << e->name() << "\n";
		if (e->name() == std::string("OBJECTS"))
		{
			object_root = e;
		}
	}

	
	// now parse the objects
	ParseObjects(object_root, pObjects);
	return true;
}


	void StateParser::ParseObjects(rapidxml::xml_node<> *pStateRoot, std::vector<GameObject*> *pObjects)
	{
		for (rapidxml::xml_node<>* e = pStateRoot->first_node(); e != NULL; e = e->next_sibling())
		{
			int x, y, width, height, numFrames, callbackID, animSpeed = 1;
			std::string textureID;
			x = atoi(e->first_attribute("x")->value());
			y = atoi(e->first_attribute("y")->value());
			width = atoi(e->first_attribute("width")->value());
			height = atoi(e->first_attribute("height")->value());
			textureID = e->first_attribute("textureID")->value();
			numFrames = atoi(e->first_attribute("numFrames")->value());
			callbackID = atoi(e->first_attribute("callbackID")->value());
	//		animSpeed = atoi(e->first_attribute("animSpeed")->value());
			
			std::cout << "Type Of Object " << e->first_attribute("type")->value();

			GameObject* pGameObject = GameObjectFactory::Instance()->Create(e->first_attribute("type")->value());
			pGameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));
			pObjects->push_back(pGameObject);
		}
	}
	void StateParser::ParseTextures(rapidxml::xml_node<>* pStateRoot, std::vector<std::string> *pTextureIDs)
	{

		for (rapidxml::xml_node<>* e = pStateRoot->first_node(); e !=
			NULL; e = e->next_sibling())
		{
			std::string filenameAttribute = e->first_attribute("filename")->value();
			std::string idAttribute = e->first_attribute("ID")->value();
			pTextureIDs->push_back(idAttribute); // push into list
			TextureManager::Instance()->load(filenameAttribute, idAttribute, Game::Instance()->GetRenderer());
		}

	}
