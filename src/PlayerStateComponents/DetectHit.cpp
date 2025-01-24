#include "DetectHit.h"

namespace RB::PlayerStateComponents
{
	void DetectHit::OnEnter()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* attacker = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::PlayerState* attackerState = RB::Players::PlayerState::GetPlayerState(attacker->GetPlayerID());
		RB::Sprites::SpriteType attackerSpriteType = attackerState->GetSpriteType();

		std::cout << std::endl;
		std::cout << " --- attacker detecting hit | player " << attacker->GetPlayerID_int() << " | starting sprite: " << attackerSpriteType._to_string() << " --- " << std::endl; 
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
		auto playerController = GET_PLAYER_CONTROLLER;
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;

		//std::cout << "detecting hit.." << std::endl;

		RB::Players::iPlayer* attacker = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		RB::Players::iPlayer* target = playerController->GetOtherPlayer(attacker);

		// cannot be hit once dead
		if (target->GetHP() <= 0)
		{
			return false;
		}

		RB::Players::PlayerState* attackerState = RB::Players::PlayerState::GetPlayerState(attacker->GetPlayerID());
		RB::Players::PlayerState* enemyState = RB::Players::PlayerState::GetPlayerState(target->GetPlayerID());

		if (attackerState == nullptr || enemyState == nullptr)
		{
			//std::cout << "state nullptr" << std::endl;

			return false;
		}
		else
		{
			std::cout << "fixed update count: " << attackerState->GetCumulatedFixedUpdates() << " | attacker state: " << attackerState->GetSpriteType()._to_string() << std::endl;
		}

		RB::Sprites::SpriteType attackerSpriteType = attackerState->GetSpriteType();
		RB::Sprites::SpriteType targetSpriteType = enemyState->GetSpriteType();

		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		RB::Render::iAnimationObj* attackerAniObj = playerAnimationController->GetCurrentAnimationObj(attacker->GetPlayerID(), attackerSpriteType);
		RB::Render::iAnimationObj* targetAniObj = playerAnimationController->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteType);

		RB::HBox::Loaded_HB_Data* attackerData = RB::HBox::iAttackBoxDataController::Get()->GetData(attackerSpriteType);
		RB::HBox::Loaded_HB_Data* targetData = targetBoxDataController->GetData(targetSpriteType);

		if (attackerData == nullptr || targetData == nullptr)
		{
			return false;
		}

		if (attackerAniObj == nullptr || targetAniObj == nullptr)
		{
			return false;
		}

		RB::HBox::AABB_Set* attackerAABBs = attackerData->GetHBoxDataByFrame(attackerAniObj->GetCurrentIndex());
		RB::HBox::AABB_Set* targetAABBs = targetData->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());

		const auto& vec_Attacker_AABB_Sets = attackerAABBs->GetSelector()->GetVector();
		const auto& vec_Target_AABB_Sets = targetAABBs->GetSelector()->GetVector();

		for (auto i = vec_Attacker_AABB_Sets.begin(); i != vec_Attacker_AABB_Sets.end(); ++i)
		{
			//std::cout << "checking owner aabb" << std::endl;

			//get owner AABB
			RB::Collisions::AABB attackerBox = (*i);
			RB::Collisions::AABB attackerBox_WorldPos = attackerBox.GetWorldPos(attacker->GetPosition(), attacker->IsFacingRight());

			//skip if width or height is 0
			if (attackerBox_WorldPos.GetWidthHeight().x <= 0.001f || attackerBox_WorldPos.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (auto j = vec_Target_AABB_Sets.begin(); j != vec_Target_AABB_Sets.end(); ++j)
			{
				//std::cout << "checking target aabb" << std::endl;

				//get target AABB
				RB::Collisions::AABB targetBox = (*j);
				RB::Collisions::AABB targetBox_WorldPos = targetBox.GetWorldPos(target->GetPosition(), attacker->IsFacingRight());

				//compare
				RB::Vector2 col;

				if (attackerBox_WorldPos.IsCollidingAgainst(targetBox_WorldPos, col))
				{
					//std::cout << "aabb collision" << std::endl;

					collisionResult.mAttacker = attacker;
					collisionResult.mTarget = target;
					collisionResult.mCollisionPoint = col;
					collisionResult.mAttackerSpriteType = attackerSpriteType;

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
		//register new attack
		RB::Collisions::AttackRegister reg;
		reg.attacker = collisionResult.mAttacker;
		reg.target = collisionResult.mTarget;
		reg.collisionPoint = collisionResult.mCollisionPoint;
		reg.attackerSpriteType = collisionResult.mAttackerSpriteType;
		reg.targetIsOnRightSide = collisionResult.mAttacker->OtherPlayerIsOnRightSide();
		reg.targetIsCrouching = collisionResult.mTarget->IsCrouching();
		reg.collisionType = collisionResult.mCollisionType;

		RB::Collisions::iAttackRegisterController::Get()->RegisterAttack(reg);

		_hits++;
		_fixedUpdatesSinceLastHit = 0;

		std::cout << std::endl;
		std::string strAttackerSprite = collisionResult.mAttackerSpriteType._to_string();
		std::cout << " --- registered hit | attacker spriteType: " << strAttackerSprite << " --- " << std::endl;
		std::cout << "attackerID: " << reg.attacker->GetPlayerID_int() << std::endl;
		std::cout << "attacker fixedupdate count: " << _state->GetCumulatedFixedUpdates() << std::endl;
		std::cout << "hit count: " << _hits << std::endl;
		std::cout << "collisionType: " << std::to_string((int)collisionResult.mCollisionType) << std::endl;
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