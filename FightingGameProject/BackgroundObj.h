#pragma once
#include <cmath>
#include "olcPixelGameEngine.h"
#include "SpriteEnum.h"
#include "SpriteObj.h"

#include "iCamController.h"

namespace RB::Background
{
	class BackgroundObj
	{
	public:
		BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, float_t percentage);
		~BackgroundObj() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		float_t _percentage = 0.0f;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		olc::vf2d _renderSize = { 0.0f ,0.0f };
		olc::vf2d _position = { 0.0f, 0.0f };
		RB::Render::SpriteObj _spriteObj;
	};
}