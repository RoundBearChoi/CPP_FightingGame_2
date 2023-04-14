#pragma once
#include <vector>
#include "SpriteID.h"
#include "AnimationRenderer.h"
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
		AnimationRenderer* GetAnimation(RB::Sprites::SpriteID spriteID);

	private:
		std::vector<AnimationRenderer*> _animationRenderer;
	};
}