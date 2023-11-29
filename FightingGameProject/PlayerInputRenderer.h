#pragma once

#include "Sprites.h"

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init(Sprites* sprites);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		void _RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint);

		Sprites* _sprites = nullptr;
	};
}