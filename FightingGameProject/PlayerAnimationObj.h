#pragma once
#include "olcPixelGameEngine.h"
#include "AnimationRenderer.h"
#include "SpriteEnum.h"
#include "SkipFixedUpdates.h"
#include "AnimationRenderSettings.h"

#include "iPlayerAnimationObj.h"
#include "iPlayer.h"

namespace RB::Render
{
	class PlayerAnimationObj : public iPlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer);
		~PlayerAnimationObj() = default;

	public:
		void OnFixedUpdate() override;

		void UpdateAnimationIndex() override;
		void ManualAddAnimationIndex(int32_t amount) override;
		void LimitAnimationIndex() override;
		olc::vf2d GetSourceSize() override;
		olc::vf2d GetSourcePos(olc::vf2d sourceSize) override;
		olc::vf2d GetRenderSize() override;
		olc::vf2d GetRenderOffset() override;
		RB::Players::iPlayer* GetPlayer() override;
		const AnimationSpecs& GetAnimationSpecs() override;
		int32_t GetCurrentIndex() override;
		void RenderAnimation() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		AnimationRenderer* _animationRenderer = nullptr;
		int32_t _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}