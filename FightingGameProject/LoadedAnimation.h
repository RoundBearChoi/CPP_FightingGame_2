#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "CurrentCam.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class LoadedAnimation
	{
	public:
		LoadedAnimation(AnimationSpecs specs);
		~LoadedAnimation();

	public:
		AnimationSpecs GetAnimationSpecs();
		void RenderAnimation(AnimationRenderSettings animationRenderSettings);

	private:
		AnimationSpecs _animationSpecs;
	};
}