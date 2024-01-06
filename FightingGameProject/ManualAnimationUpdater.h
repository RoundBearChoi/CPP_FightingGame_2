#pragma once
#include "SpriteType.h"

namespace RB::Render
{
	class ManualAnimationUpdater
	{
	public:
		ManualAnimationUpdater() = default;
		~ManualAnimationUpdater() = default;

	public:
		void OnEnter(RB::Sprites::SpriteType spriteEnum);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		RB::Sprites::SpriteType _spriteEnum = RB::Sprites::SpriteType::NONE;
	};
}