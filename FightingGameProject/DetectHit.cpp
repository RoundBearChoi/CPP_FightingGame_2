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
		RB::Players::iPlayer* target = RB::Players::PLAYER_CONTROLLER->GetOtherPlayer(owner);

		RB::PlayerStates::PlayerState* ownerState = RB::PlayerStates::ActivePlayerStates::GetPlayerState(owner->GetPlayerID());
		RB::PlayerStates::PlayerState* enemyState = RB::PlayerStates::ActivePlayerStates::GetPlayerState(target->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum ownerSpriteEnum = ownerState->GetSpriteEnum();
		RB::Sprites::SpriteEnum targetSpriteEnum = enemyState->GetSpriteEnum();
		
		RB::Render::iAnimationObj* ownerAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetCurrentAnimationObj(owner->GetPlayerID(), ownerSpriteEnum);
		RB::Render::iAnimationObj* targetAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteEnum);

		RB::HBox::HBoxDataList* ownerList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(ownerSpriteEnum);
		RB::HBox::HBoxDataList* targetList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(targetSpriteEnum);

		if (ownerList == nullptr || targetList == nullptr)
		{
			return;
		}

		RB::HBox::HBoxData* ownerData = ownerList->GetHBoxDataByFrame(ownerAniObj->GetCurrentIndex());
		RB::HBox::HBoxData* targetData = targetList->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());

		size_t ownerAABBCount = ownerData->GetAABBCount();
		size_t targetAABBCount = targetData->GetAABBCount();
		
		for (size_t i = 0; i < ownerAABBCount; i++)
		{
			//get owner AABB
			RB::Collisions::AABB& ownerAABB = ownerData->GetAABB(i);
			olc::vi2d ownerPos = owner->GetPosition();
			RB::Collisions::AABB ownerWorldAABB = ownerAABB.GetWorldPos(owner->GetPosition(), owner->IsFacingRight()); //OtherPlayerIsOnRightSide());

			//skip if width or height is 0
			if (ownerWorldAABB.GetWidthHeight().x <= 0.001 || ownerWorldAABB.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (size_t j = 0; j < targetAABBCount; j++)
			{
				//get target AABB
				RB::Collisions::AABB& targetAABB = targetData->GetAABB(j);
				olc::vi2d targetPos = target->GetPosition();
				RB::Collisions::AABB targetWorldAABB = targetAABB.GetWorldPos(target->GetPosition(), owner->IsFacingRight()); //target->OtherPlayerIsOnRightSide());

				//compare
				olc::vf2d col;

				if (ownerWorldAABB.IsCollidingAgainst(targetWorldAABB, col))
				{
					//_col = col;

					RB::Render::VFX_ANIMATION_CONTROLLER->InstantiateAnimation(RB::Sprites::SpriteEnum::vfx_hiteffect_0, col);

					std::cout << "update count: " << _state->GetCumulatedFixedUpdates() << std::endl;
					std::cout << "player " << owner->GetPlayerID_int() << " hit player " << target->GetPlayerID_int() << std::endl;
					std::cout << std::endl;

					if (RB::Collisions::ATTACK_REGISTER_CONTROLLER->GetRegisteredAttackCount(target->GetPlayerID()) <= 0)
					{
						target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::P0_Wince());

						if (RB::Collisions::GENERAL_HIT_STOP_CONTROLLER != nullptr)
						{
							RB::Collisions::GENERAL_HIT_STOP_CONTROLLER->AddSkipFrames(2);
						}
					}

					return;
				}
			}
		}
	}
}