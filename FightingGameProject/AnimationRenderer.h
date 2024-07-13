#pragma once

#include <vector>

#include "RenderSettings.h"
#include "AnimationSpecs.h"
#include "SizeChangeObj.h"

namespace RB::Render
{
	class AnimationRenderer
	{
	public:
		AnimationRenderer(AnimationSpecs specs);
		~AnimationRenderer() = default;

	public:
		void OnFixedUpdate();

	public:
		const AnimationSpecs& GetAnimationSpecs();
		void RenderAnimation(const RenderSettings& renderSettings);

	private:
		std::vector<SizeChangeObj> _vecSizeChangeObjs;
		AnimationSpecs _animationSpecs;
	};
}
