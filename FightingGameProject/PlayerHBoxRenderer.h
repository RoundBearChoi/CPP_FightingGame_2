#pragma once
#include "SpriteObj.h"
#include "AABB.h"

#include "ActivePlayerStates.h"
#include "HBoxType.h"

#include "iHurtBoxDataController.h"
#include "iHitBoxDataController.h"
#include "iPlayerAnimationController.h"
#include "iPlayerController.h"

namespace RB::Render
{
	class PlayerHBoxRenderer
	{
	public:
		PlayerHBoxRenderer() = default;
		~PlayerHBoxRenderer() = default;

	public:
		void Init(SpriteObj* spriteRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderHBox(RB::Players::PlayerID playerID, RB::HBox::HBoxType boxType);

	private:
		void _Render(RB::Players::iPlayer* player, RB::HBox::HBoxData* data, olc::Pixel color);

		SpriteObj* _spriteObj = nullptr;
	};
}