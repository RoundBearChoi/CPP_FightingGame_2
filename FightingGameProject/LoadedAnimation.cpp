#include "LoadedAnimation.h"

namespace RB::Render
{
	LoadedAnimation::LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID)
	{
		_widthIndexes = widthIndexes;
		_heightIndexes = heightIndexes;
		_totalIndexes = totalIndexes;
		_spriteID = spriteID;
	}

	LoadedAnimation::~LoadedAnimation()
	{

	}
}