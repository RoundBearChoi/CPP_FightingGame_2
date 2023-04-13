#pragma once
#include "iPlayer.h"
#include "LoadedAnimation.h"
#include "SpriteID.h"

namespace RB::Render
{
	class PlayerAnimationObj
	{
	public:
		PlayerAnimationObj(RB::Players::iPlayer* owner, LoadedAnimation* loadedAnimation);
		~PlayerAnimationObj();

	public:
		void Init();

	public:
		RB::Sprites::SpriteID GetSpriteID();
		RB::Players::iPlayer* GetPlayer();

	public:
		void RenderAnimation();

	private:
		RB::Players::iPlayer* _player = nullptr;
		LoadedAnimation* _loadedAnimation = nullptr;
		unsigned int _currentIndex = 0;
	};
}