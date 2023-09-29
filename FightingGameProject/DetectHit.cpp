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
		
		RB::Render::iPlayerAnimationObj* ownerAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(owner->GetPlayerID(), ownerSpriteEnum);
		RB::Render::iPlayerAnimationObj* enemyAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(enemy->GetPlayerID(), enemySpriteEnum);

		RB::HBox::HBoxDataList* ownerList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(ownerSpriteEnum);
		RB::HBox::HBoxDataList* enemyList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(enemySpriteEnum);

		RB::HBox::HBoxData* ownerData = ownerList->GetHBoxDataByFrame(ownerAniObj->GetCurrentIndex());
		RB::HBox::HBoxData* enemyData = enemyList->GetHBoxDataByFrame(enemyAniObj->GetCurrentIndex());

		size_t ownerAABBCount = ownerData->GetAABBCount();
		size_t enemyAABBCount = enemyData->GetAABBCount();
		
		for (size_t i = 0; i < ownerAABBCount; i++)
		{
			for (size_t j = 0; j < enemyAABBCount; j++)
			{
				RB::Collisions::AABB& ownerAABB = ownerData->GetAABB(i);
				RB::Collisions::AABB& enemyAABB = enemyData->GetAABB(j);

				if (ownerAABB.IsCollidingAgainst(enemyAABB))
				{
					std::cout << "update count: " << _state->GetCumulatedFixedUpdates() << std::endl;
					std::cout << "player " << owner->GetPlayerID_int() << " hit player " << enemy->GetPlayerID_int() << std::endl;
					std::cout << std::endl;

					return;
				}
			}
		}
	}
}