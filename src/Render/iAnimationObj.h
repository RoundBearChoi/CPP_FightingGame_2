#pragma once

#include "AnimationSpecs.h"
#include "CustomRender.h"
#include "RenderScaleMultiplierObj.h"
#include "RenderRotationObj.h"
#include "RenderTransparencyObj.h"

#include "../Players/iPlayer.h"
#include "RenderTransparencyObj.h"

namespace RB::Render
{
	//class RenderScaleMultiplierObj; // forward declare

	class iAnimationObj
	{
	public:
		virtual ~iAnimationObj() = default;

		virtual void OnFixedUpdate() = 0;

	public:
		virtual void FaceRight(bool faceRight) = 0;
		virtual void UpdateAnimationIndex() = 0;
		virtual void ManualIncreaseAnimationIndex() = 0;
		virtual void ManualDecreaseAnimationIndex() = 0;
		virtual void CycleAnimationIndex() = 0;
		virtual RB::Vector2 GetSourceSize() = 0;
		virtual float GetRenderScale() = 0;
		virtual RB::Vector2 GetSourcePos(RB::Vector2 sourceSize) = 0;
		virtual RB::Vector2 GetRenderOffset() = 0;
		virtual Players::iPlayer* GetPlayer() = 0;
		virtual const AnimationSpecs& GetAnimationSpecs() const = 0;
		virtual unsigned int GetCurrentIndex() = 0;
		virtual void RenderAnimation() = 0;
		virtual void SetWorldPos(const RB::Vector2& pos) = 0;
		virtual unsigned int GetFixedUpdateCount() = 0;
		virtual void AddRenderScaleMultiplierObj(RenderScaleMultiplierObj* obj) = 0;
		virtual void AddRenderRotationObj(RenderRotationObj* obj) = 0;
		virtual void AddRenderTransparency(RenderTransparencyObj* obj) = 0;
		virtual float GetRenderScaleMultiplier() = 0;
		virtual float GetRotation() = 0;
		virtual int GetTransparency() = 0;
	};
}
