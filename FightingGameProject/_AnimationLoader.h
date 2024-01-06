#pragma once
#include <vector>
#include "SpriteType.h"
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
		AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);

	private:
		std::vector<AnimationRenderer*> _animationRenderer;
	};
}