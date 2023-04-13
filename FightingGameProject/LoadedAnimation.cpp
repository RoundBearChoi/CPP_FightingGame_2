#include "LoadedAnimation.h"

namespace RB::Animations
{
	LoadedAnimation::LoadedAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes)
	{
		_widthIndexes = widthIndexes;
		_heightIndexes = heightIndexes;
		_totalIndexes = totalIndexes;
	}

	LoadedAnimation::~LoadedAnimation()
	{

	}
}