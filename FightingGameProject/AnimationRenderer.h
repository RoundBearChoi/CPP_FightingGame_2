#pragma once
#include <vector>
#include "SpriteID.h"
#include "LoadedAnimation.h"

namespace RB::Render
{
	class AnimationRenderer
	{
		public:
		AnimationRenderer();
		~AnimationRenderer();

	public:
		void Init();
		void LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalSprites, unsigned int skipFixedUpdates, RB::Sprites::SpriteID spriteID, RB::Sprites::LoadedSprite* loadedSprite);
		LoadedAnimation* GetAnimation(RB::Sprites::SpriteID spriteID);

	private:
		std::vector<LoadedAnimation*> _loadedAnimations;
	};
}