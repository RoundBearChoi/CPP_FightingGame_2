#pragma once
#include <cmath>
#include "olcPixelGameEngine.h"
#include "SpriteEnum.h"

namespace RB::Background
{
	class BackgroundObj
	{
	public:
		BackgroundObj(RB::Sprites::SpriteEnum spriteEnum, olc::vf2d pos, float_t percentage);
		~BackgroundObj() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		float_t _percentage = 0.0f;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		olc::vf2d _position = { 0.0f, 0.0f };
	};
}