#include "DetectHit.h"

#include "PlayerState.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iVFXAnimationController.h"
#include "iHitBoxDataController.h"
#include "iHurtBoxDataController.h"
#include "iGeneralHitStopController.h"

#include "P0_Wince.h"

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

		RB::HBox::Loaded_HB_Data* ownerData = RB::HBox::iHitBoxDataController::instance->GetData(ownerSpriteEnum);
		RB::HBox::Loaded_HB_Data* targetData = RB::HBox::iHurtBoxDataController::instance->GetData(targetSpriteEnum);

		if (ownerData == nullptr || targetData == nullptr)
		{
			return;
		}

		if (ownerAniObj == nullptr || targetAniObj == nullptr)
		{
			return;
		}

		RB::HBox::AABB_Set* ownerAABBs = ownerData->GetHBoxDataByFrame(ownerAniObj->GetCurrentIndex());
		RB::HBox::AABB_Set* targetAABBs = targetData->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());
		
		const auto& vec_Owner_AABB_Sets = ownerAABBs->GetSelector()->GetVector();
		const auto& vec_Target_AABB_Sets = targetAABBs->GetSelector()->GetVector();

		for (auto i = vec_Owner_AABB_Sets.begin(); i != vec_Owner_AABB_Sets.end(); ++i)
		{
			//get owner AABB
			RB::Collisions::AABB ownerBox = (*i);
			RB::Collisions::AABB ownerBox_WorldPos = ownerBox.GetWorldPos(owner->GetPosition(), owner->IsFacingRight());

			//skip if width or height is 0
			if (ownerBox_WorldPos.GetWidthHeight().x <= 0.001f || ownerBox_WorldPos.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (auto j = vec_Target_AABB_Sets.begin(); j != vec_Target_AABB_Sets.end(); ++j)
			{
				//get target AABB
				RB::Collisions::AABB targetBox = (*j);
				RB::Collisions::AABB targetBox_WorldPos = targetBox.GetWorldPos(target->GetPosition(), owner->IsFacingRight());

				//compare
				olc::vf2d col;

				if (ownerBox_WorldPos.IsCollidingAgainst(targetBox_WorldPos, col))
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