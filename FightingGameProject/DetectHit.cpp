#include "DetectHit.h"

#include "AttackSpecs.h"

#include "PlayerState.h"
#include "iPlayerController.h"
#include "iPlayerAnimationController.h"
#include "iAttackBoxDataController.h"
#include "iTargetBoxDataController.h"
#include "iAttackRegisterController.h"
#include "iAttackSpecsController.h"

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
		_ProcessHit();
		_AddFixedUpdatesSinceLastHit();
	}
	void DetectHit::_ProcessHit()
	{
		RB::Players::iPlayer* owner = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* target = RB::Players::iPlayerController::Get()->GetOtherPlayer(owner);

		RB::PlayerStates::PlayerState* ownerState = RB::PlayerStates::PlayerState::GetPlayerState(owner->GetPlayerID());
		RB::PlayerStates::PlayerState* enemyState = RB::PlayerStates::PlayerState::GetPlayerState(target->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteType ownerSpriteType = ownerState->GetSpriteType();
		RB::Sprites::SpriteType targetSpriteType = enemyState->GetSpriteType();

		RB::Render::iAnimationObj* ownerAniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(owner->GetPlayerID(), ownerSpriteType);
		RB::Render::iAnimationObj* targetAniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteType);

		RB::HBox::Loaded_HB_Data* ownerData = RB::HBox::iAttackBoxDataController::Get()->GetData(ownerSpriteType);
		RB::HBox::Loaded_HB_Data* targetData = RB::HBox::iTargetBoxDataController::Get()->GetData(targetSpriteType);

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
					//check max hit count
					const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(ownerSpriteType);

					if (_hits == 0 || _fixedUpdatesSinceLastHit > attackSpecs.mMinimumFixedUpdatesSinceHit)
					{
						if (_hits <= attackSpecs.mMaxHits)
						{
							_RegisterHit(owner, target, col, ownerSpriteType);
						}
					}

					return;
				}
			}
		}
	}

	void DetectHit::_RegisterHit(RB::Players::iPlayer* owner, RB::Players::iPlayer* target, olc::vf2d collisionPoint, RB::Sprites::SpriteType ownerSpriteType)
	{
		//register attack
		RB::Collisions::AttackRegister reg;
		reg.attacker = owner;
		reg.target = target;
		reg.collisionPoint = collisionPoint;
		reg.attackerSpriteType = ownerSpriteType;
		reg.targetIsOnRightSide = owner->OtherPlayerIsOnRightSide();

		RB::Collisions::iAttackRegisterController::Get()->RegisterAttack(reg);

		_hits++;
		_fixedUpdatesSinceLastHit = 0;

		std::cout << "attacker fixedupdate count: " << _state->GetCumulatedFixedUpdates() << std::endl;
		std::cout << "fixedupdates since last hit: " << _fixedUpdatesSinceLastHit << std::endl;
		std::cout << "hit count: " << _hits << std::endl;
		std::cout << "player " << owner->GetPlayerID_int() << " hit player " << target->GetPlayerID_int() << std::endl;
		std::cout << std::endl;
	}

	void DetectHit::_AddFixedUpdatesSinceLastHit()
	{
		if (_hits > 0)
		{
			_fixedUpdatesSinceLastHit++;
		}
	}
}