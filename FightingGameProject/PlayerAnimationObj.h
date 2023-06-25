#pragma once
#include "olcPixelGameEngine.h"
#include "AnimationRenderer.h"
#include "SpriteEnum.h"
#include "SkipFixedUpdates.h"
#include "AnimationRenderSettings.h"

#include "iPlayerAnimationObj.h"
#include "iPlayer.h"
//#include "AnimationSpecs.h"

namespace RB::Render
{
	class PlayerAnimationObj : public iPlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer);
		~PlayerAnimationObj() = default;

	public:
		void OnFixedUpdate();

		void UpdateAnimationIndex();
		void ManualAddAnimationIndex(int32_t amount);
		void LimitAnimationIndex();
		olc::vf2d GetSourceSize();
		olc::vf2d GetSourcePos(olc::vf2d sourceSize);
		olc::vf2d GetRenderSize();
		olc::vf2d GetRenderOffset();
		RB::Players::iPlayer* GetPlayer();
		const AnimationSpecs& GetAnimationSpecs();
		int32_t GetCurrentIndex();
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		AnimationRenderer* _animationRenderer = nullptr;
		int32_t _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}