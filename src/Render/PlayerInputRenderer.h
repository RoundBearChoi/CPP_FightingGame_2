#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"
#include "../Sprites/SpriteContainer.h"
#include "../Sprites/SpriteType.h"

#include "../Players/iPlayerController.h"
#include "../Input/iInputController.h"

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init(Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();
		void RenderInput(bool render);

	private:
		bool _render = true;
		void _RenderPlayerInputIcons(Players::PLAYER_TYPE playerID, int yPos);
		void _RenderIcon(Sprites::SPRITE_TYPE spriteType, RB::Vector2 pos, olc::Pixel tint);
		Sprites::SPRITE_TYPE _GetSpriteType(const Input::PlayerInput& playerInput);

		Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}
