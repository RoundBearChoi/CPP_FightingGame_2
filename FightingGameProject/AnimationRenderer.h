#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "CurrentCam.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class AnimationRenderer
	{
	public:
		AnimationRenderer(AnimationSpecs specs);
		~AnimationRenderer();

	public:
		const AnimationSpecs& GetAnimationSpecs();
		void RenderAnimation(const AnimationRenderSettings& animationRenderSettings);

	private:
		AnimationSpecs _animationSpecs;
	};
}