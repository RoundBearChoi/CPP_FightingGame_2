#include "AnimationLoader.h"

namespace RB::Animations
{
	AnimationLoader::AnimationLoader()
	{

	}
	AnimationLoader::~AnimationLoader()
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			delete _loadedAnimations[i];
		}
	}

	void AnimationLoader::Init()
	{

	}

	void AnimationLoader::LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID)
	{

	}
}