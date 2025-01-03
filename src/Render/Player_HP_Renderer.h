#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"
#include "../Sprites/SpriteContainer.h"

#include "../Players/iPlayerController.h"

namespace RB::Render
{
	class Player_HP_Renderer
	{
	public:
		Player_HP_Renderer() = default;
		~Player_HP_Renderer() = default;

	public:
		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

    private:
        void _RenderPlayerHPBar(RB::Players::PlayerID playerID);

	private:
		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}