#pragma once
#include <vector>
#include "SpriteID.h"
#include "LoadedAnimation.h"

namespace RB::Animations
{
	class AnimationLoader
	{
		public:
		AnimationLoader();
		~AnimationLoader();

	public:
		void Init();
		void LoadAnimation(unsigned int widthIndexes, unsigned int heightIndexes, unsigned int totalIndexes, RB::Sprites::SpriteID spriteID);

	private:
		std::vector<LoadedAnimation*> _loadedAnimations;
	};
}