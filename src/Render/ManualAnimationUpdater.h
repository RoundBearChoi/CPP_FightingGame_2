#pragma once

#include "iPlayerAnimationController.h"

#include "../Sprites/SpriteType.h"

namespace RB::Render
{
	class ManualAnimationUpdater
	{
	public:
		ManualAnimationUpdater() = default;
		~ManualAnimationUpdater() = default;

	public:
		void OnEnter(Sprites::SPRITE_TYPE spriteType);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		Sprites::SPRITE_TYPE _spriteType = Sprites::SPRITE_TYPE::NONE;
	};
}
