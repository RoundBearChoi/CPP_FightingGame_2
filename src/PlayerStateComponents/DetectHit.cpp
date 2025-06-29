#include "DetectHit.h"

namespace RB::PlayerStateComponents
{
	void DetectHit::OnEnter()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* attacker = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		Players::PlayerState* attackerState = Players::PlayerState::GetPlayerState(attacker->GetPlayerID());
		Sprites::SpriteType attackerSpriteType = attackerState->GetSpriteType();
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
		auto attackSpecsController = GET_ATTACK_SPECS_CONTROLLER;

		Collisions::CollisionResult collisionResult;

		if (_HitDetected(collisionResult))
		{
			//check max hit count
			const Collisions::AttackSpecs& attackSpecs = attackSpecsController->GetAttackSpecs(collisionResult.mAttackerSpriteType);

			if (_hits == 0 || _fixedUpdatesSinceLastHit > attackSpecs.mMinimumFixedUpdatesSinceHit)
			{
				if (_hits <= attackSpecs.mMaxHits)
				{
					_RegisterHit(collisionResult);
				}
			}
		}
	}

	bool DetectHit::_HitDetected(Collisions::CollisionResult& collisionResult)
	{
		auto playerController = GET_PLAYER_CONTROLLER;
		auto targetBoxDataController = GET_TARGET_BOX_DATA_CONTROLLER;
		auto attackBoxDataController = GET_ATTACK_BOX_DATA_CONTROLLER;

		Players::iPlayer* attacker = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());
		Players::iPlayer* target = playerController->GetOtherPlayer(attacker);

		// cannot be hit once dead
		if (target->GetHP() <= 0)
		{
			return false;
		}

		Players::PlayerState* attackerState = Players::PlayerState::GetPlayerState(attacker->GetPlayerID());
		Players::PlayerState* enemyState = Players::PlayerState::GetPlayerState(target->GetPlayerID());

		if (attackerState == nullptr || enemyState == nullptr)
		{
			return false;
		}

		Sprites::SpriteType attackerSpriteType = attackerState->GetSpriteType();
		Sprites::SpriteType targetSpriteType = enemyState->GetSpriteType();

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		Render::iAnimationObj* attackerAniObj = playerAnimationController->GetCurrentAnimationObj(attacker->GetPlayerID(), attackerSpriteType);
		Render::iAnimationObj* targetAniObj = playerAnimationController->GetCurrentAnimationObj(target->GetPlayerID(), targetSpriteType);

		HBox::Loaded_HB_Data* attackerData = attackBoxDataController->GetData(attackerSpriteType);
		HBox::Loaded_HB_Data* targetData = targetBoxDataController->GetData(targetSpriteType);

		if (attackerData == nullptr || targetData == nullptr)
		{
			return false;
		}

		if (attackerAniObj == nullptr || targetAniObj == nullptr)
		{
			return false;
		}

		HBox::AABB_Set* attackerAABBs = attackerData->GetHBoxDataByFrame(attackerAniObj->GetCurrentIndex());
		HBox::AABB_Set* targetAABBs = targetData->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());

		const auto& vec_Attacker_AABB_Sets = attackerAABBs->GetSelector()->GetVector();
		const auto& vec_Target_AABB_Sets = targetAABBs->GetSelector()->GetVector();

		for (auto i = vec_Attacker_AABB_Sets.begin(); i != vec_Attacker_AABB_Sets.end(); ++i)
		{
			//get owner AABB
			Collisions::AABB attackerBox = (*i);
			Collisions::AABB attackerBox_WorldPos = attackerBox.GetWorldPos(attacker->GetPosition(), attacker->IsFacingRight());

			//skip if width or height is 0
			if (attackerBox_WorldPos.GetWidthHeight().x <= 0.001f || attackerBox_WorldPos.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			for (auto j = vec_Target_AABB_Sets.begin(); j != vec_Target_AABB_Sets.end(); ++j)
			{
				//get target AABB
				Collisions::AABB targetBox = (*j);
				Collisions::AABB targetBox_WorldPos = targetBox.GetWorldPos(target->GetPosition(), attacker->IsFacingRight());

				//compare
				RB::Vector2 col;

				if (attackerBox_WorldPos.IsCollidingAgainst(targetBox_WorldPos, col))
				{
					collisionResult.mAttacker = attacker;
					collisionResult.mTarget = target;
					collisionResult.mCollisionPoint = col;
					collisionResult.mAttackerSpriteType = attackerSpriteType;

					float* targetParts = target->GetPlayerCollider()->GetBodyParts();
					
					float part0y = targetParts[0];
					float part1y = targetParts[1];

					if (col.y > part0y)
					{
						collisionResult.mCollisionType = Collisions::CollisionType::LEGS;
					}
					else if (col.y < part1y)
					{
						collisionResult.mCollisionType = Collisions::CollisionType::HEAD;
					}
					else
					{
						collisionResult.mCollisionType = Collisions::CollisionType::BODY;
					}

					return true;
				}
			}
		}

		return false;
	}

	void DetectHit::_RegisterHit(Collisions::CollisionResult& collisionResult)
	{
		auto attackRegisterController = GET_ATTACK_REGISTER_CONTROLLER;

		//register new attack
		Collisions::AttackRegister reg;
		reg.attacker = collisionResult.mAttacker;
		reg.target = collisionResult.mTarget;
		reg.collisionPoint = collisionResult.mCollisionPoint;
		reg.attackerSpriteType = collisionResult.mAttackerSpriteType;
		reg.targetIsOnRightSide = collisionResult.mAttacker->OtherPlayerIsOnRightSide();
		reg.targetIsCrouching = collisionResult.mTarget->IsCrouching();
		reg.collisionType = collisionResult.mCollisionType;

		attackRegisterController->RegisterAttack(reg);

		_hits++;
		_fixedUpdatesSinceLastHit = 0;

		//std::cout << std::endl;
		//std::string strAttackerSprite = collisionResult.mAttackerSpriteType._to_string();
		//std::cout << " --- registered hit | attacker spriteType: " << strAttackerSprite << " --- " << std::endl;
		//std::cout << "attackerID: " << reg.attacker->GetPlayerID_int() << std::endl;
		//std::cout << "attacker fixedupdate count: " << _state->GetCumulatedFixedUpdates() << std::endl;
		//std::cout << "hit count: " << _hits << std::endl;
		//std::cout << "collisionType: " << std::to_string((int)collisionResult.mCollisionType) << std::endl;
		//std::cout << std::endl;
	}

	void DetectHit::_AddFixedUpdatesSinceLastHit()
	{
		if (_hits > 0)
		{
			_fixedUpdatesSinceLastHit++;
		}
	}
}
