#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "AnimationRenderer.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class _AnimationLoader
	{
		public:
		_AnimationLoader() = default;
		~_AnimationLoader();

	public:
		void Init();
		void LoadAnimation(AnimationSpecs specs);
		AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteEnum);

	private:
		std::vector<AnimationRenderer*> _animationRenderer;
	};
}