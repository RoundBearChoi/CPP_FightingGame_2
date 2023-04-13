#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "PivotType.h"
#include "LoadedSprite.h"

namespace RB::Render
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite);
		~LoadedAnimation();

	public:
		RB::Sprites::SpriteID GetSpriteID();

	public:
		void RenderAnimation(unsigned int index, olc::vi2d pos, RB::Sprites::PivotType pivot);
		unsigned int GetFixedUpdateSkipCount();

	private:
		unsigned int _widthIndexes;
		unsigned int _heightIndexes;
		unsigned int _totalIndexes;
		unsigned int _skipFixedUpdates;
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		RB::Sprites::LoadedSprite* _loadedSprite = nullptr;
	};
}