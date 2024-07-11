#include "SpriteTypeLoader.h"

#include "JGetter.h"
#include "Parser.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path)
	{
		//std::string str = RB::JSON::LoadJSONFile(path);
		//json_value_s* root = json_parse(str.c_str(), str.size());
		//json_object_s* jObj = json_value_as_object(root);

		RB::JSON::Parser parser;
		parser.LoadJSON(path);
		auto jObj = parser.GetObj(0);

		auto element = RB::JSON::Parser::GetElement(*jObj, 0); //RB::JSON::GetElementNFromObj(*jObj, 0);

		auto subElement = RB::JSON::Parser::GetElement(*element, 0); //RB::JSON::GetElementInsideElement(*rootElement); //get sprite enum string

		std::string spriteEnumStr = RB::JSON::GetString_FromElement(*subElement);

		RB::Sprites::SpriteType loadedSpriteType = RB::Sprites::SpriteType::_from_string(spriteEnumStr.c_str());

		//free(root);

		return loadedSpriteType;
	}
}
