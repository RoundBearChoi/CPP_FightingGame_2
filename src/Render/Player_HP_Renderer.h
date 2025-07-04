#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"
#include "../EaseCalculator.h"

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
		void Init(Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();
		void RenderHP(bool render);

    private:
        void _RenderPlayerHPBar(RB::Players::PLAYER_TYPE playerID);
		void _UpdatePlayerHPBar(RB::Players::PLAYER_TYPE playerID);
		EaseCalculator _p1_calculator;
		EaseCalculator _p2_calculator;

	private:
		Sprites::SpriteContainer* _spriteContainer = nullptr;
		bool _render = true;
	};
}
