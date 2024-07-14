#pragma once
#include "olcPixelGameEngine.h"

#include <vector>

#include "SkipFixedUpdates.h"
#include "AnimationRenderer.h"
#include "RenderScaleMultiplierObj.h"

#include "iAnimationObj.h"
#include "iPlayer.h"

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
		olc::vf2d GetSourceSize() override;
		olc::vf2d GetSourcePos(olc::vf2d sourceSize) override;
		float GetRenderScale() override;
		olc::vf2d GetRenderOffset() override;
		RB::Players::iPlayer* GetPlayer() override;
		const AnimationSpecs& GetAnimationSpecs() const override;
		unsigned int GetCurrentIndex() override;
		void RenderAnimation() override;
		void SetWorldPos(const olc::vf2d& pos) override;
		unsigned int GetFixedUpdateCount() override;
		void AddRenderScaleMultiplierObj(RenderScaleMultiplierObj obj) override;
		float GetRenderScaleMultiplier() override;
		float GetLastRenderScale() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		//int _ownerPlayerID = 0;
		AnimationRenderer* _animationRenderer = nullptr;
		RB::Sprites::PivotType _pivotType = RB::Sprites::PivotType::BOTTOM_CENTER;
		unsigned int _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<AnimationObj> _customFixedUpdate;
		olc::vf2d _worldPos = { 0, 0 };
		std::vector<RenderScaleMultiplierObj> _vecMultiplierObjs;
		float _lastRenderScaleMultiplier = 1.0f;
	};
}
