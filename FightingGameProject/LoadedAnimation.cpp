#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite)
	{
		_widthIndexes = widthIndexes;
		_heightIndexes = heightIndexes;
		_totalSprites = totalSprites;
		_skipFixedUpdates = skipFixedUpdates;
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

	unsigned int LoadedAnimation::GetWidthIndexes()
	{
		return _widthIndexes;
	}

	unsigned int LoadedAnimation::GetHeightIndexes()
	{
		return _heightIndexes;
	}

	unsigned int LoadedAnimation::GetTotalSprites()
	{
		return _totalSprites;
	}

	void LoadedAnimation::RenderAnimation(unsigned int index, olc::vi2d worldPos, RB::Sprites::PivotType pivot)
	{
		if (_spriteID == RB::Sprites::SpriteID::NONE)
		{
			return;
		}


	}

	unsigned int LoadedAnimation::GetFixedUpdateSkipCount()
	{
		return _skipFixedUpdates;
	}
}