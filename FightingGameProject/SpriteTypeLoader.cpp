#include "SpriteTypeLoader.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path)
	{
		RB::JSON::JParser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);
		auto element = RB::JSON::JParser::GetElement(*jObj, 0);
		auto subElement = RB::JSON::JParser::GetElement(*element, 0);

		std::string spriteEnumStr = RB::JSON::JParser::GetString_FromElement(*subElement);

		RB::Sprites::SpriteType loadedSpriteType = RB::Sprites::SpriteType::_from_string(spriteEnumStr.c_str());

		return loadedSpriteType;
	}
}
