#pragma once

#include <vector>

#include "../olcPixelGameEngine.h"

#include "AnimationSpecs.h"

#include "../Vector2.h"
#include "../FlipQuad.h"
#include "../RenderSettings.h"
#include "../GetQuadOnPivot.h"

#include "../iCamController.h"

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
		AnimationSpecs _animationSpecs;
	};
}
