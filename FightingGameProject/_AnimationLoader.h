#pragma once
#include <vector>
#include "SpriteType.h"
#include "AnimationRenderer.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class _AnimationRendererLoader
	{
		public:
		_AnimationRendererLoader() = default;
		~_AnimationRendererLoader();

	public:
		void Init();
		void LoadAnimationRenderer(AnimationSpecs specs);
		AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);

	private:
		std::vector<AnimationRenderer*> _animationRenderer;
	};
}
