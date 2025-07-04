#pragma once

#include "../olcPixelGameEngine.h"

#include "iPlayerAnimationController.h"

#include "../Vector2.h"
#include "../Sprites/SpriteContainer.h"
#include "../Players/PlayerState.h"

#include "../HBox/Loaded_HB_Data.h"
#include "../HBox/AABB_Set.h"
#include "../HBox/HBoxType.h"
#include "../HBox/iAttackBoxDataController.h"
#include "../HBox/iTargetBoxDataController.h"

#include "../Players/iPlayer.h"
#include "../Players/iPlayerController.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(Players::PLAYER_TYPE playerID, HBox::HBoxType boxType);

	private:
		void _Render(Players::iPlayer* player, HBox::AABB_Set* AABBs, olc::Pixel color);

		Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}
