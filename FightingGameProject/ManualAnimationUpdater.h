#pragma once
#include "SpriteEnum.h"

#include "iPlayerAnimationController.h"

namespace RB::Render
{
	class ManualAnimationUpdater
	{
	public:
		ManualAnimationUpdater() = default;
		~ManualAnimationUpdater() = default;

	public:
		void OnEnter(RB::Sprites::SpriteEnum spriteEnum);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}