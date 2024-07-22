#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"
#include "../SpriteContainer.h"
#include "../SpriteType.h"

#include "../iPlayerController.h"
#include "../iInputController.h"

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		void _RenderPlayerInputIcons(RB::Players::PlayerID playerID, int yPos);
		void _RenderIcon(RB::Sprites::SpriteType spriteType, RB::Vector2 pos, olc::Pixel tint);
		RB::Sprites::SpriteType _GetSpriteType(const RB::Input::PlayerInput& playerInput);

		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}
