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

		void Init(RB::Sprites::SpriteLoader* sprites);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		void _RenderPlayerInputIcons(RB::Players::PlayerID playerID, int yPos);
		void _RenderIcon(RB::Sprites::SpriteEnum spriteEnum, olc::vi2d pos, olc::Pixel tint);
		RB::Sprites::SpriteEnum _GetSpriteEnum(const RB::Input::PlayerInput& playerInput);

		RB::Sprites::SpriteLoader* _sprites = nullptr;
	};
}