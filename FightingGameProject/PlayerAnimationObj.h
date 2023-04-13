#pragma once
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