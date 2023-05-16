#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "AnimationRenderer.h"
#include "SpriteEnum.h"
#include "SkipFixedUpdates.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class PlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer);
		~PlayerAnimationObj() = default;

	public:
		void OnFixedUpdate();

	public:
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

	public:
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		AnimationRenderer* _animationRenderer = nullptr;
		int32_t _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}