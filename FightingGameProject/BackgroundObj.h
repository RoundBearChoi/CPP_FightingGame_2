#pragma once
#include <cmath>
#include "SpriteEnum.h"

namespace RB::Background
{
	class BackgroundObj
	{
	public:
		BackgroundObj() = default;
		~BackgroundObj() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		float_t _percentage = 0.0f;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}