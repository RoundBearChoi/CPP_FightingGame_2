#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "LoadedAnimation.h"
#include "SpriteID.h"
#include "SkipFixedUpdates.h"

namespace RB::Render
{
	class PlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, LoadedAnimation* loadedAnimation);
		~PlayerAnimationObj();

	public:
		void OnFixedUpdate();

	public:
		void IncreaseAnimationIndex();
		void UpdateSource();
		RB::Sprites::SpriteID GetSpriteID();
		RB::Players::iPlayer* GetPlayer();

	public:
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _player = nullptr;
		LoadedAnimation* _loadedAnimation = nullptr;
		unsigned int _currentIndex = 0;
		olc::vf2d _sourcePos = { 0.0f, 0.0f };
		olc::vf2d _sourceSize = { 0.0f, 0.0f };
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}