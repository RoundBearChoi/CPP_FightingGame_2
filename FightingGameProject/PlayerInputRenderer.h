#pragma once

#include "Sprites.h"
#include "SpriteEnum.h"

#include "iPlayerController.h"
#include "iInputController.h"

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
		void _RenderPlayerOneInputIcons();
		void _RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint);
		RB::Sprites::SpriteEnum _GetSpriteEnum(const RB::Input::PlayerInput& playerInput);

		Sprites* _sprites = nullptr;
	};
}