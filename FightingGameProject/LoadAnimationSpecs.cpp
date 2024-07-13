#include "LoadAnimationSpecs.h"

#include <cassert>

#include "JParser.h"

namespace RB::Render
{
	AnimationSpecs LoadAnimationSpecsFromJSON(std::string path, AnimationContainer& container)
	{
		RB::JSON::JParser parser;

		parser.LoadJSON(path);

		auto obj = parser.GetObj(0);
		auto element = RB::JSON::JParser::GetElement(*obj, 0);
		auto subElement = RB::JSON::JParser::GetElement(*element, 0);
		auto vecAll = RB::JSON::JParser::GetAllElements(*subElement);

		std::string strEnum = RB::JSON::JParser::GetString_FromElement(*vecAll[0]);
		int xTileCount = RB::JSON::JParser::GetInt_FromElement(*vecAll[1]);
		int yTileCount = RB::JSON::JParser::GetInt_FromElement(*vecAll[2]);
		int totalSprites = RB::JSON::JParser::GetInt_FromElement(*vecAll[3]);
		int skipFixedUpdates = RB::JSON::JParser::GetInt_FromElement(*vecAll[4]);
		float renderScale = RB::JSON::JParser::GetFloat_FromElement(*vecAll[5]);
		int playOnceInt = RB::JSON::JParser::GetInt_FromElement(*vecAll[6]);
		bool playOnce = playOnceInt == 0 ? false : true;

		//load sprites first
		bool loadedSprite = container.LoadSprite("PNG files/Aku/" + strEnum + ".png", RB::Sprites::SpriteType::_from_string(strEnum.c_str()));

		assert(loadedSprite);

		AnimationSpecs specs;

		specs.mX_TileCount = xTileCount;
		specs.mY_TileCount = yTileCount;
		specs.mTotalSprites = totalSprites;
		specs.mSkipFixedUpdates = skipFixedUpdates;
		specs.mRenderScale = renderScale;
		specs.mPlayOnce = playOnce;
		specs.mSpriteType = RB::Sprites::SpriteType::_from_string(strEnum.c_str());

		return specs;
	}
}
