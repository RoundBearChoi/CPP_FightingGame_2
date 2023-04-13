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
		void OnUpdate();
		void OnFixedUpdate();

	public:
		RB::Sprites::SpriteID GetSpriteID();

	private:
		RB::Players::iPlayer* _player = nullptr;
		LoadedAnimation* _loadedAnimation = nullptr;
	};
}