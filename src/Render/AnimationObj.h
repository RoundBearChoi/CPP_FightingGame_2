#pragma once

#include <vector>
#include <cmath>

#include "AnimationRenderer.h"
#include "CustomRenderContainer.h"
#include "RenderRotationObj.h"
#include "RenderScaleMultiplierObj.h"
#include "RenderTransparencyObj.h"

#include "iAnimationObj.h"

#include "../Vector2.h"

#include "../Updaters/Skipper.h"

#include "../Players/iPlayer.h"

namespace RB::Render
{
	class AnimationObj : public iAnimationObj
	{
	public:
		AnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer, Sprites::PivotType pivotType);
		~AnimationObj() override;

	public:
		void OnFixedUpdate() override;

	public:
		void FaceRight(bool faceRight) override;
		void UpdateAnimationIndex() override;
		void ManualIncreaseAnimationIndex() override;
		void ManualDecreaseAnimationIndex() override;
		void CycleAnimationIndex() override;
		RB::Vector2 GetSourceSize() override;
		RB::Vector2 GetSourcePos(RB::Vector2 sourceSize) override;
		float GetRenderScale() override;
		RB::Vector2 GetRenderOffset() override;
		RB::Players::iPlayer* GetPlayer() override;
		const AnimationSpecs& GetAnimationSpecs() const override;
		unsigned int GetCurrentIndex() override;
		void RenderAnimation() override;
		void SetWorldPos(const RB::Vector2& pos) override;
		unsigned int GetFixedUpdateCount() override;
		void AddRenderScaleMultiplierObj(RenderScaleMultiplierObj* obj) override;
		void AddRenderRotationObj(RenderRotationObj* obj) override;
		void AddRenderTransparency(RenderTransparencyObj* obj) override;
		float GetRenderScaleMultiplier() override;
		float GetRotation() override;
		int GetTransparency() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		bool _faceRight = true;
		AnimationRenderer* _animationRenderer = nullptr;
		Sprites::PivotType _pivotType = Sprites::PivotType::BOTTOM_CENTER;
		unsigned int _currentIndex = 0;
		RB::Updaters::Skipper _skippedFixedUpdates;
		RB::Vector2 _worldPos = { 0, 0 };
		CustomRenderContainer<RenderScaleMultiplierObj> _customRenderScales;
		CustomRenderContainer<RenderRotationObj> _customRotations;
		CustomRenderContainer<RenderTransparencyObj> _customTransparency;
		AnimationSpecs _emptySpecs;
	};
}
