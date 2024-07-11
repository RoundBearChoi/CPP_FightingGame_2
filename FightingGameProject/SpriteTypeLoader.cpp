#include "SpriteTypeLoader.h"

#include "JGetter.h"
#include "Parser.h"

namespace RB::Sprites
{
	RB::Sprites::SpriteType LoadSpriteType(const std::string& path)
	{
		RB::JSON::Parser parser;
		parser.LoadJSON(path);

		auto jObj = parser.GetObj(0);
		auto element = RB::JSON::Parser::GetElement(*jObj, 0);
		auto subElement = RB::JSON::Parser::GetElement(*element, 0);

		std::string spriteEnumStr = RB::JSON::Parser::GetString_FromElement(*subElement);

		RB::Sprites::SpriteType loadedSpriteType = RB::Sprites::SpriteType::_from_string(spriteEnumStr.c_str());

		return loadedSpriteType;
	}
}
