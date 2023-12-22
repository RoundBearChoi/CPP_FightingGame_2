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
		RB::Players::iPlayer* owner = RB::Players::iPlayerController::instance->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* target = RB::Players::iPlayerController::instance->GetOtherPlayer(owner);

		RB::PlayerStates::PlayerState* ownerState = RB::PlayerStates::PlayerState::GetPlayerState(owner->GetPlayerID());
		RB::PlayerStates::PlayerState* enemyState = RB::PlayerStates::PlayerState::GetPlayerState(target->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum ownerSpriteEnum = ownerState->GetSpriteEnum();
		RB::Sprites::SpriteEnum targetSpriteEnum = enemyState->GetSpriteEnum();
		
		RB::Render::iAnimationObj* ownerAniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(owner->GetPlayerID(), ownerSpriteEnum);
		RB::Render::iAnimationObj* targetAniObj = RB::Render::iPlayerAnimationController::instance->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteEnum);

		RB::HBox::HBoxDataList* ownerList = RB::HBox::iHitBoxDataController::instance->GetDataList(ownerSpriteEnum);
		RB::HBox::HBoxDataList* targetList = RB::HBox::iHurtBoxDataController::instance->GetDataList(targetSpriteEnum);

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
			RB::Collisions::AABB ownerWorldAABB = ownerAABB.GetWorldPos(owner->GetPosition(), owner->IsFacingRight());

			//skip if width or height is 0
			if (ownerWorldAABB.GetWidthHeight().x <= 0.001f || ownerWorldAABB.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (size_t j = 0; j < targetAABBCount; j++)
			{
				//get target AABB
				RB::Collisions::AABB& targetAABB = targetData->GetAABB(j);
				olc::vi2d targetPos = target->GetPosition();
				RB::Collisions::AABB targetWorldAABB = targetAABB.GetWorldPos(target->GetPosition(), owner->IsFacingRight());

				//compare
				olc::vf2d col;

				if (ownerWorldAABB.IsCollidingAgainst(targetWorldAABB, col))
				{
					//temp - decouple by using attackregister?

					RB::Render::iVFXAnimationController::instance->InstantiateAnimation(RB::Sprites::SpriteEnum::vfx_hiteffect_0, col);

					std::cout << "update count: " << _state->GetCumulatedFixedUpdates() << std::endl;
					std::cout << "player " << owner->GetPlayerID_int() << " hit player " << target->GetPlayerID_int() << std::endl;
					std::cout << std::endl;

					target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::Aku::P0_Wince());

					if (RB::Collisions::iGeneralHitStopController::instance != nullptr)
					{
						RB::Collisions::iGeneralHitStopController::instance->AddSkipFrames(3);
					}

					return;
				}
			}
		}
	}
}