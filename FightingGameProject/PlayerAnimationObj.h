#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "AnimationRenderer.h"
#include "SpriteID.h"
#include "SkipFixedUpdates.h"
#include "AnimationRenderSettings.h"
#include "AnimationSpecs.h"

namespace RB::Render
{
	class PlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, AnimationRenderer* animationRenderer);
		~PlayerAnimationObj();

	public:
		void OnFixedUpdate();

	public:
		void IncreaseAnimationIndex();
		olc::vf2d GetSourceSize();
		olc::vf2d GetSourcePos(olc::vf2d sourceSize);
		olc::vf2d GetRenderSize();
		RB::Players::iPlayer* GetPlayer();
		const AnimationSpecs& GetAnimationSpecs();

	public:
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _player = nullptr;
		AnimationRenderer* _animationRenderer = nullptr;
		unsigned int _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}