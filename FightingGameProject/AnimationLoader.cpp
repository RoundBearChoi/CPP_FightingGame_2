#include "AnimationLoader.h"

namespace RB::Render
{
	AnimationRenderer::AnimationRenderer()
	{

	}
	AnimationRenderer::~AnimationRenderer()
	{
		for (int i = 0; i < _loadedAnimations.size(); i++)
		{
			delete _loadedAnimations[i];
		}
	}

	void AnimationRenderer::Init()
	{

	}

	void AnimationRenderer::LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID)
	{
		LoadedAnimation* loaded = new LoadedAnimation(widthIndexes, heightIndexes, totalIndexes, spriteID);

		_loadedAnimations.push_back(loaded);
	}
}