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
		RB::Collisions::CollisionResult collisionResult;

		if (_HitDetected(collisionResult))
		{
			//check max hit count
			const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(collisionResult.mOwnerSpriteType);

			if (_hits == 0 || _fixedUpdatesSinceLastHit > attackSpecs.mMinimumFixedUpdatesSinceHit)
			{
				if (_hits <= attackSpecs.mMaxHits)
				{
					_RegisterHit(collisionResult);
				}
			}
		}
	}

	bool DetectHit::_HitDetected(RB::Collisions::CollisionResult& collisionResult)
	{
		RB::Players::iPlayer* owner = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* target = RB::Players::iPlayerController::Get()->GetOtherPlayer(owner);

		RB::PlayerStates::PlayerState* ownerState = RB::PlayerStates::PlayerState::GetPlayerState(owner->GetPlayerID());
		RB::PlayerStates::PlayerState* enemyState = RB::PlayerStates::PlayerState::GetPlayerState(target->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			return false;
		}

		RB::Sprites::SpriteType ownerSpriteType = ownerState->GetSpriteType();
		RB::Sprites::SpriteType targetSpriteType = enemyState->GetSpriteType();

		RB::Render::iAnimationObj* ownerAniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(owner->GetPlayerID(), ownerSpriteType);
		RB::Render::iAnimationObj* targetAniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteType);

		RB::HBox::Loaded_HB_Data* ownerData = RB::HBox::iAttackBoxDataController::Get()->GetData(ownerSpriteType);
		RB::HBox::Loaded_HB_Data* targetData = RB::HBox::iTargetBoxDataController::Get()->GetData(targetSpriteType);

		if (ownerData == nullptr || targetData == nullptr)
		{
			return false;
		}

		if (ownerAniObj == nullptr || targetAniObj == nullptr)
		{
			return false;
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
					collisionResult.mOwner = owner;
					collisionResult.mTarget = target;
					collisionResult.mCollisionPoint = col;
					collisionResult.mOwnerSpriteType = ownerSpriteType;

					return true;
				}
			}
		}

		return false;
	}

	void DetectHit::_RegisterHit(RB::Collisions::CollisionResult& collisionResult)
	{
		//register attack
		RB::Collisions::AttackRegister reg;
		reg.attacker = collisionResult.mOwner;
		reg.target = collisionResult.mTarget;
		reg.collisionPoint = collisionResult.mCollisionPoint;
		reg.attackerSpriteType = collisionResult.mOwnerSpriteType;
		reg.targetIsOnRightSide = collisionResult.mOwner->OtherPlayerIsOnRightSide();
		reg.attackCollisionYType = _GetAttackCollisionYType(collisionResult.mTarget, collisionResult.mCollisionPoint);

		RB::Collisions::iAttackRegisterController::Get()->RegisterAttack(reg);

		_hits++;
		_fixedUpdatesSinceLastHit = 0;

		std::cout << "attacker fixedupdate count: " << _state->GetCumulatedFixedUpdates() << std::endl;
		std::cout << "fixedupdates since last hit: " << _fixedUpdatesSinceLastHit << std::endl;
		std::cout << "hit count: " << _hits << std::endl;
		std::cout << "player " << collisionResult.mOwner->GetPlayerID_int() << " hit player " << collisionResult.mTarget->GetPlayerID_int() << std::endl;
		std::cout << std::endl;
	}

	void DetectHit::_AddFixedUpdatesSinceLastHit()
	{
		if (_hits > 0)
		{
			_fixedUpdatesSinceLastHit++;
		}
	}

	RB::Collisions::AttackCollisionYType DetectHit::_GetAttackCollisionYType(RB::Players::iPlayer* target, olc::vf2d& collisionPoint)
	{
		//get attack collision y type
		float targetBottomY = target->GetPosition().y;
		float targetPlayerColliderHeight = target->GetPlayerCollider()->GetPlayerBox().y;
		float targetTopY = targetBottomY - targetPlayerColliderHeight; //up y is negative

		float oneThird = targetPlayerColliderHeight * 0.3f;

		RB::Collisions::AttackCollisionYType yType = RB::Collisions::AttackCollisionYType::NONE;

		if (collisionPoint.y <= targetTopY + oneThird)
		{
			yType = RB::Collisions::AttackCollisionYType::HEAD;
		}
		else if (collisionPoint.y <= targetTopY + (oneThird * 2.0f))
		{
			yType = RB::Collisions::AttackCollisionYType::BODY;
		}
		else
		{
			yType = RB::Collisions::AttackCollisionYType::LEG;
		}

		return yType;
	}
}