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
		void OnEnter(Sprites::SpriteType spriteType);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		Sprites::SpriteType _spriteType = Sprites::SpriteType::NONE;
	};
}
