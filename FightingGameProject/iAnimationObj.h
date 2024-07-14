#pragma once

#include "iPlayer.h"

#include "AnimationSpecs.h"
#include "RenderScaleMultiplierObj.h"

namespace RB::Render
{
	class RenderScaleMultiplierObj; // forward declare

	class iAnimationObj
	{
	public:
		virtual void OnFixedUpdate() = 0;

		virtual void UpdateAnimationIndex() = 0;
		virtual void ManualIncreaseAnimationIndex() = 0;
		virtual void ManualDecreaseAnimationIndex() = 0;
		virtual void CycleAnimationIndex() = 0;
		virtual olc::vf2d GetSourceSize() = 0;
		virtual float GetRenderScale() = 0;
		virtual olc::vf2d GetSourcePos(olc::vf2d sourceSize) = 0;
		virtual olc::vf2d GetRenderOffset() = 0;
		virtual RB::Players::iPlayer* GetPlayer() = 0;
		virtual const AnimationSpecs& GetAnimationSpecs() const = 0;
		virtual unsigned int GetCurrentIndex() = 0;
		virtual void RenderAnimation() = 0;
		virtual void SetWorldPos(const olc::vf2d& pos) = 0;
		virtual unsigned int GetFixedUpdateCount() = 0;
		virtual void AddRenderScaleMultiplierObj(RenderScaleMultiplierObj obj) = 0;
		virtual float GetRenderScaleMultiplier() = 0;
	};
}
