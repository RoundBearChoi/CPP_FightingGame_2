#include "SpriteTypeLoader.h"

#include "JGetter.h"

namespace RB::Updaters
{
	RB::Sprites::SpriteType SpriteTypeLoader::LoadSpriteType(std::string path)
	{
		std::string str = RB::JSON::LoadJSONFile(path);
		json_value_s* root = json_parse(str.c_str(), str.size());

		json_object_s* jObj = json_value_as_object(root);

		json_object_element_s* rootElement = RB::JSON::GetElementNFromObj(*jObj, 0);

		json_object_element_s* spriteEnumElement = RB::JSON::GetElementInsideElement(*rootElement); //get sprite enum string
		std::string spriteEnumStr = RB::JSON::GetString_FromElement(*spriteEnumElement);

		return RB::Sprites::SpriteType::NONE;
	}
}