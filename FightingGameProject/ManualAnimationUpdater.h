#pragma once
#include "PlayerAnimationController.h"
#include "SpriteID.h"

namespace RB::Render
{
	class ManualAnimationUpdater
	{
	public:
		ManualAnimationUpdater() = default;
		~ManualAnimationUpdater() = default;

	public:
		void Init(RB::Sprites::SpriteID spriteID);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		RB::Render::PlayerAnimationController* _playerAnimationController = nullptr;
	};
}