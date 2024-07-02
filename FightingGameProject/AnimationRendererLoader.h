#pragma once
#include <vector>
#include "SpriteType.h"
#include "AnimationRenderer.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class AnimationRendererLoader
	{
		public:
		AnimationRendererLoader() = default;
		~AnimationRendererLoader();

	public:
		void Init();
		AnimationRenderer* LoadAnimationRenderer(AnimationSpecs specs);
		//AnimationRenderer* GetAnimationRenderer(RB::Sprites::SpriteType spriteType);
	};
}
