#pragma once

#include <vector>

#include "AnimationRenderer.h"

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
		void AddRenderScaleMultiplierObj(RenderScaleMultiplierObj obj) override;
		void AddRenderRotationObj(RenderRotationObj obj) override;
		float GetRenderScaleMultiplier() override;
		float GetRotation() override;
		float GetLastRenderScale() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		//int _ownerPlayerID = 0;
		AnimationRenderer* _animationRenderer = nullptr;
		RB::Sprites::PivotType _pivotType = RB::Sprites::PivotType::BOTTOM_CENTER;
		unsigned int _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<AnimationObj> _customFixedUpdate;
		RB::Vector2 _worldPos = { 0, 0 };
		std::vector<RenderScaleMultiplierObj> _vecMultiplierObjs;
		std::vector<RenderRotationObj> _vecRotationObjs;
		float _lastRenderScaleMultiplier = 1.0f;
		float _lastRotation = 0.0f;
		AnimationSpecs _emptySpecs;
	};
}
