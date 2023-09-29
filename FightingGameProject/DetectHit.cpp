#include "DetectHit.h"

namespace RB::PlayerStateComponents
{
	void DetectHit::OnEnter()
	{

	}

	void DetectHit::OnUpdate()
	{

	}

	void DetectHit::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* enemy = RB::Players::PLAYER_CONTROLLER->GetOtherPlayer(owner);

		RB::PlayerStates::PlayerState* ownerState = RB::PlayerStates::ActivePlayerStates::GetPlayerState(owner->GetPlayerID());
		RB::PlayerStates::PlayerState* enemyState = RB::PlayerStates::ActivePlayerStates::GetPlayerState(enemy->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum ownerSpriteEnum = ownerState->GetSpriteEnum();
		RB::Sprites::SpriteEnum enemySpriteEnum = enemyState->GetSpriteEnum();
		
		RB::HBox::HBoxDataList* ownerList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(ownerSpriteEnum);
		RB::HBox::HBoxDataList* enemyList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(enemySpriteEnum);
	}
}