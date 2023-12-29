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

		RB::HBox::HBox_Layer_1* ownerHB_L1 = RB::HBox::iHitBoxDataController::instance->GetDataList(ownerSpriteEnum);
		RB::HBox::HBox_Layer_1* targetHB_L1 = RB::HBox::iHurtBoxDataController::instance->Get_L1(targetSpriteEnum);

		if (ownerHB_L1 == nullptr || targetHB_L1 == nullptr)
		{
			return;
		}

		if (ownerAniObj == nullptr || targetAniObj == nullptr)
		{
			return;
		}

		RB::HBox::HBox_Layer_0* ownerHB_L0 = ownerHB_L1->GetHBoxDataByFrame(ownerAniObj->GetCurrentIndex());
		RB::HBox::HBox_Layer_0* targetHB_L0 = targetHB_L1->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());
		
		const auto& vecOwner = ownerHB_L0->GetSelector()->GetVector();
		const auto& vecTarget = targetHB_L0->GetSelector()->GetVector();

		for (auto i = vecOwner.begin(); i != vecOwner.end(); ++i)
		{
			//get owner AABB
			RB::Collisions::AABB ownerAABB = (*i);
			olc::vi2d ownerPos = owner->GetPosition();
			RB::Collisions::AABB ownerWorldAABB = ownerAABB.GetWorldPos(owner->GetPosition(), owner->IsFacingRight());

			//skip if width or height is 0
			if (ownerWorldAABB.GetWidthHeight().x <= 0.001f || ownerWorldAABB.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (auto j = vecTarget.begin(); j != vecTarget.end(); ++j)
			{
				//get target AABB
				RB::Collisions::AABB targetAABB = (*j);
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