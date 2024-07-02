#pragma once
#include "RenderSettings.h"
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
		void RenderAnimation(const RenderSettings& renderSettings);

	private:
		AnimationSpecs _animationSpecs;
	};
}