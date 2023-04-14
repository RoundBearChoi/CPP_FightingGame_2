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
		olc::vf2d GetSourceSize();
		olc::vf2d GetSourcePos(olc::vf2d sourceSize);
		RB::Sprites::SpriteID GetSpriteID();
		RB::Players::iPlayer* GetPlayer();

	public:
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _player = nullptr;
		LoadedAnimation* _loadedAnimation = nullptr;
		unsigned int _currentIndex = 0;
		RB::Updaters::SkipFixedUpdates<PlayerAnimationObj> _skipFixedUpdates;
	};
}