#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(unsigned int xTileCount, unsigned int yTileCount, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite)
	{
		_xTileCount = xTileCount;
		_yTileCount = yTileCount;
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

	unsigned int LoadedAnimation::GetXTileCount()
	{
		return _xTileCount;
	}

	unsigned int LoadedAnimation::GetYTileCount()
	{
		return _yTileCount;
	}

	unsigned int LoadedAnimation::GetTotalSprites()
	{
		return _totalSprites;
	}

	void LoadedAnimation::RenderAnimation(unsigned int index, olc::vf2d sourcePos, olc::vf2d sourceSize, olc::vi2d worldPos, RB::Sprites::PivotType pivot)
	{
		if (_spriteID == RB::Sprites::SpriteID::NONE)
		{
			return;
		}

		std::array<olc::vf2d, 4> points;

		//temp
		float x = 100.0f;
		float y = 100.0f;
		float width = 100.0f;
		float height = 100.0f;

		points[0] = { (float)x - (float)width / 2.0f, (float)y - (float)height };
		points[1] = { (float)x - (float)width / 2.0f, (float)y };
		points[2] = { (float)x + (float)width / 2.0f, (float)y };
		points[3] = { (float)x + (float)width / 2.0f, (float)y - (float)height };

		//olc::Renderer::ptrPGE->DrawPartialWarpedDecal(d, points, sourcePos, sourceSize);
	}

	unsigned int LoadedAnimation::GetFixedUpdateSkipCount()
	{
		return _skipFixedUpdates;
	}

	olc::vi2d LoadedAnimation::GetSpriteSize()
	{
		return _loadedSprite->GetSpriteSize();
	}
}