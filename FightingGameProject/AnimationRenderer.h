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
		void LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID);
		LoadedAnimation* GetAnimation(RB::Sprites::SpriteID spriteID);

	private:
		std::vector<LoadedAnimation*> _loadedAnimations;
	};
}