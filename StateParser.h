#include <iostream>
#include <vector>
#include <string>
#include "rapidxml/rapidxml.hpp"

class GameObject;
class StateParser
{
public:
	bool ParseState(
		const char* stateFile, 
		std::string stateID, 
		std::vector<GameObject*> *pObjects, 
		std::vector<std::string> *pTextureIDs);

private:
	
	void ParseObjects(rapidxml::xml_node<> *pStateRoot, std::vector<GameObject*> *pObjects);
	void ParseTextures(rapidxml::xml_node<>* pStateRoot, std::vector<std::string> *pTextureIDs);
};