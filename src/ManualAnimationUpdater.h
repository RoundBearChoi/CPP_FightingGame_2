#pragma once

#include "SpriteType.h"

#include "Render/iPlayerAnimationController.h"

namespace RB::Render
{
	class ManualAnimationUpdater
	{
	public:
		ManualAnimationUpdater() = default;
		~ManualAnimationUpdater() = default;

	public:
		void OnEnter(RB::Sprites::SpriteType spriteType);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
	};
}
