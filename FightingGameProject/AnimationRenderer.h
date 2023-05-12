#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteID.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"
#include "Controllers.h"
#include "CamController.h"

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

	private:
		RB::Cam::CamController* _camController = nullptr;
	};
}