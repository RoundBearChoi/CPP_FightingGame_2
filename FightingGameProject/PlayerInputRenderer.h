#pragma once

#include "SpriteLoader.h"
#include "SpriteType.h"

#include "iPlayerController.h"
#include "iInputController.h"

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init(RB::Sprites::SpriteLoader* spriteLoader);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		void _RenderPlayerInputIcons(RB::Players::PlayerID playerID, int yPos);
		void _RenderIcon(RB::Sprites::SpriteType spriteEnum, olc::vi2d pos, olc::Pixel tint);
		RB::Sprites::SpriteType _GetSpriteEnum(const RB::Input::PlayerInput& playerInput);

		RB::Sprites::SpriteLoader* _spriteLoader = nullptr;
	};
}