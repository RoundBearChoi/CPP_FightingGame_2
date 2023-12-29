#pragma once
#include "Sprites.h"
#include "AABB.h"

#include "HBoxType.h"

#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerController.h"

#include "PlayerState.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(RB::Sprites::Sprites* sprites);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType);

	private:
		void _Render(RB::Players::iPlayer* player, RB::HBox::HBox_Layer_0* L0, olc::Pixel color);

		RB::Sprites::Sprites* _sprites = nullptr;
	};
}