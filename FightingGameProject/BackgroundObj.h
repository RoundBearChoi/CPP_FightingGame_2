#pragma once
#include "olcPixelGameEngine.h"
#include "SpriteType.h"
#include "SpriteLoader.h"

namespace RB::Background
{
	class BackgroundObj
	{
	public:
		BackgroundObj(std::string path, RB::Sprites::SpriteType spriteType, float percentage);
		~BackgroundObj() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		float _percentage = 0.0f;
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
		olc::vf2d _renderSize = { 0.0f ,0.0f };
		olc::vf2d _position = { 0.0f, 0.0f };
		RB::Sprites::SpriteLoader _spriteLoader;
	};
}