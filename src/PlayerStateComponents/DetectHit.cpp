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
		_ProcessHit();
		_AddFixedUpdatesSinceLastHit();
	}

	void DetectHit::_ProcessHit()
	{
		//std::cout << "proccesssing hit.." << std::endl;

		RB::Collisions::CollisionResult collisionResult;

		if (_HitDetected(collisionResult))
		{
			//check max hit count
			const RB::Collisions::AttackSpecs& attackSpecs = RB::Collisions::iAttackSpecsController::Get()->GetAttackSpecs(collisionResult.mAttackerSpriteType);

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
		//std::cout << "detecting hit.." << std::endl;

		RB::Players::iPlayer* owner = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* target = RB::Players::iPlayerController::Get()->GetOtherPlayer(owner);

		RB::Players::PlayerState* ownerState = RB::Players::PlayerState::GetPlayerState(owner->GetPlayerID());
		RB::Players::PlayerState* enemyState = RB::Players::PlayerState::GetPlayerState(target->GetPlayerID());

		if (ownerState == nullptr || enemyState == nullptr)
		{
			//std::cout << "state nullptr" << std::endl;

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
			//std::cout << "checking owner aabb" << std::endl;

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
				//std::cout << "checking target aabb" << std::endl;

				//get target AABB
				RB::Collisions::AABB targetBox = (*j);
				RB::Collisions::AABB targetBox_WorldPos = targetBox.GetWorldPos(target->GetPosition(), owner->IsFacingRight());

				//compare
				RB::Vector2 col;

				if (ownerBox_WorldPos.IsCollidingAgainst(targetBox_WorldPos, col))
				{
					//std::cout << "aabb collision" << std::endl;

					collisionResult.mAttacker = owner;
					collisionResult.mTarget = target;
					collisionResult.mCollisionPoint = col;
					collisionResult.mAttackerSpriteType = ownerSpriteType;

					float* targetParts = target->GetPlayerCollider()->GetBodyParts();
					
					float part0y = targetParts[0];
					float part1y = targetParts[1];

					if (col.y > part0y)
					{
						collisionResult.mCollisionType = RB::Collisions::CollisionType::LEGS;
					}
					else if (col.y < part1y)
					{
						collisionResult.mCollisionType = RB::Collisions::CollisionType::HEAD;
					}
					else
					{
						collisionResult.mCollisionType = RB::Collisions::CollisionType::BODY;
					}

					//std::cout << "hit detected" << std::endl;

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
		reg.attacker = collisionResult.mAttacker;
		reg.target = collisionResult.mTarget;
		reg.collisionPoint = collisionResult.mCollisionPoint;
		reg.attackerSpriteType = collisionResult.mAttackerSpriteType;
		reg.targetIsOnRightSide = collisionResult.mAttacker->OtherPlayerIsOnRightSide();
		reg.collisionType = collisionResult.mCollisionType;

		RB::Collisions::iAttackRegisterController::Get()->RegisterAttack(reg);

		_hits++;
		_fixedUpdatesSinceLastHit = 0;

		std::cout << std::endl;
		std::string strAttackerSprite = collisionResult.mAttackerSpriteType._to_string();
		std::cout << "attacker spriteType: " << strAttackerSprite << std::endl;
		std::cout << "attackerID: " << reg.attacker->GetPlayerID_int() << std::endl;
		std::cout << "attacker fixedupdate count: " << _state->GetCumulatedFixedUpdates() << std::endl;
		std::cout << "hit count: " << _hits << std::endl;
		std::cout << "collisionType: " << std::to_string((int)collisionResult.mCollisionType) << std::endl;
	}

	void DetectHit::_AddFixedUpdatesSinceLastHit()
	{
		if (_hits > 0)
		{
			_fixedUpdatesSinceLastHit++;
		}
	}
}
