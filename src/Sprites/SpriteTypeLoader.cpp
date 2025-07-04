#include "SpriteTypeLoader.h"

namespace RB::Sprites
{
	Sprites::SPRITE_TYPE LoadSpriteType(const std::string& path)
	{
		JSON::JParser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);
		auto element = parser.GetElement(*jObj, 0);
		auto subElement = parser.GetElement(*element, 0);

		std::string spriteEnumStr = parser.GetString_FromElement(*subElement);

		Sprites::SPRITE_TYPE loadedSpriteType = Sprites::SPRITE_TYPE::_from_string(spriteEnumStr.c_str());

		return loadedSpriteType;
	}
}
