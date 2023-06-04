#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "SpriteEnum.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

#include "ControllerGetter.h"
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
		RB::Controllers::ControllerGetter<RB::Cam::CamController> _getter_camController;
	};
}