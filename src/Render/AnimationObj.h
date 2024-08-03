#pragma once

#include <vector>

#include "AnimationRenderer.h"
#include "CustomRenderContainer.h"

#include "RenderRotationObj.h"
#include "RenderScaleMultiplierObj.h"
#include "RenderTransparent.h"

#include "iAnimationObj.h"

#include "../Vector2.h"
#include "../Updaters/SkipFixedUpdates.h"

#include "../Players/iPlayer.h"

namespace RB::Render
{
	class AnimationObj : public iAnimationObj
	{
	public:
		AnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer, RB::Sprites::PivotType pivotType);
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
		float GetRenderScaleMultiplier() override;
		float GetRotation() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		bool _faceRight = true;
		AnimationRenderer* _animationRenderer = nullptr;
		RB::Sprites::PivotType _pivotType = RB::Sprites::PivotType::BOTTOM_CENTER;
		unsigned int _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<AnimationObj> _customFixedUpdate;
		RB::Vector2 _worldPos = { 0, 0 };
		CustomRenderContainer<RenderScaleMultiplierObj> _customRenderScales;
		CustomRenderContainer<RenderRotationObj> _customRotations;
		AnimationSpecs _emptySpecs;
	};
}
