#pragma once

#include "SpriteID.h"

namespace RB::Render
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID);
		~LoadedAnimation();

	public:

	private:
		unsigned int _widthIndexes;
		unsigned int _heightIndexes;
		unsigned int _totalIndexes;
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
	};
}