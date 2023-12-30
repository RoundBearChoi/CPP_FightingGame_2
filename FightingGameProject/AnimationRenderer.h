#pragma once
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class AnimationRenderer
	{
	public:
		AnimationRenderer(AnimationSpecs specs);
		~AnimationRenderer() = default;

	public:
		const AnimationSpecs& GetAnimationSpecs();
		void RenderAnimation(const AnimationRenderSettings& animationRenderSettings);

	private:
		AnimationSpecs _animationSpecs;
	};
}