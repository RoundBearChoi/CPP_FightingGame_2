#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite)
	{
		_widthIndexes = widthIndexes;
		_heightIndexes = heightIndexes;
		_totalIndexes = totalIndexes;
		_spriteID = spriteID;
		_loadedSprite = loadedSprite;
	}

	LoadedAnimation::~LoadedAnimation()
	{

	}

	RB::Sprites::SpriteID LoadedAnimation::GetSpriteID()
	{
		return _spriteID;
	}

	void LoadedAnimation::RenderAnimation(unsigned int index, olc::vi2d pos, RB::Sprites::PivotType pivot)
	{
		if (_spriteID == RB::Sprites::SpriteID::NONE)
		{
			return;
		}


	}
}