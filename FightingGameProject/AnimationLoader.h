#pragma once
#include <vector>
#include "SpriteID.h"
#include "LoadedAnimation.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class AnimationLoader
	{
		public:
		AnimationLoader();
		~AnimationLoader();

	public:
		void Init();
		void LoadAnimation(AnimationSpecs specs);
		LoadedAnimation* GetAnimation(RB::Sprites::SpriteID spriteID);

	private:
		std::vector<LoadedAnimation*> _loadedAnimations;
	};
}