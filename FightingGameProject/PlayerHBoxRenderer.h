#pragma once

#include "olcPixelGameEngine.h"

#include "SpriteContainer.h"
#include "AABB_Set.h"
#include "HBoxType.h"

#include "iPlayer.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType);

	private:
		void _Render(RB::Players::iPlayer* player, RB::HBox::AABB_Set* AABBs, olc::Pixel color);

		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
	};
}
