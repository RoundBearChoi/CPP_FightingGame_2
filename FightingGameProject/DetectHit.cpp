#include "DetectHit.h"

namespace RB::PlayerStateComponents
{
	void DetectHit::OnEnter()
	{

	}

	void DetectHit::OnUpdate()
	{
		olc::vf2d ownerWH = _tempOwnerAABB.GetWidthHeight();

		if (ownerWH.x != 0.0f && ownerWH.y != 0.0f)
		{
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempOwnerAABB.GetBottomLeft(), olc::RED);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempOwnerAABB.GetBottomLeft() + olc::vf2d{_tempOwnerAABB.GetWidthHeight().x, 0.0f }, olc::RED);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempOwnerAABB.GetBottomLeft() + olc::vf2d{ 0.0f, -_tempOwnerAABB.GetWidthHeight().y }, olc::RED);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempOwnerAABB.GetBottomLeft() + olc::vf2d{ _tempOwnerAABB.GetWidthHeight().x, -_tempOwnerAABB.GetWidthHeight().y }, olc::RED);
		}

		olc::vf2d targetWH = _tempTargetAABB.GetWidthHeight();

		if (targetWH.x != 0.0f && targetWH.y != 0.0f)
		{
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempTargetAABB.GetBottomLeft(), olc::MAGENTA);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempTargetAABB.GetBottomLeft() + olc::vf2d{ _tempTargetAABB.GetWidthHeight().x, 0.0f }, olc::MAGENTA);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempTargetAABB.GetBottomLeft() + olc::vf2d{ 0.0f, -_tempTargetAABB.GetWidthHeight().y }, olc::MAGENTA);
			_lineRenderer.RenderLine({ 0.0f, 100.0f }, _tempTargetAABB.GetBottomLeft() + olc::vf2d{ _tempTargetAABB.GetWidthHeight().x, -_tempTargetAABB.GetWidthHeight().y }, olc::MAGENTA);
		}
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
		
		RB::Render::iPlayerAnimationObj* ownerAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(owner->GetPlayerID(), ownerSpriteEnum);
		RB::Render::iPlayerAnimationObj* targetAniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(target->GetPlayerID(), targetSpriteEnum);

		RB::HBox::HBoxDataList* ownerList = RB::HBox::HITBOX_DATA_CONTROLLER->GetDataList(ownerSpriteEnum);
		RB::HBox::HBoxDataList* targetList = RB::HBox::HURTBOX_DATA_CONTROLLER->GetDataList(targetSpriteEnum);

		RB::HBox::HBoxData* ownerData = ownerList->GetHBoxDataByFrame(ownerAniObj->GetCurrentIndex());
		RB::HBox::HBoxData* targetData = targetList->GetHBoxDataByFrame(targetAniObj->GetCurrentIndex());

		size_t ownerAABBCount = ownerData->GetAABBCount();
		size_t targetAABBCount = targetData->GetAABBCount();
		
		//gotta get worldpos

		for (size_t i = 0; i < ownerAABBCount; i++)
		{
			_tempOwnerAABB = { 0.0f, 0.0f, 0.0f, 0.0f };
			RB::Collisions::AABB& ownerAABB = ownerData->GetAABB(i);

			if (ownerAABB.GetWidthHeight().x <= 0.001f || ownerAABB.GetWidthHeight().y <= 0.001f)
			{
				continue;
			}

			olc::vi2d ownerPos = owner->GetPosition();
			RB::Collisions::AABB ownerWorldAABB = ownerAABB.GetWorldPos(owner->GetPosition(), owner->OtherPlayerIsOnRightSide());
			_tempOwnerAABB = ownerWorldAABB;

			for (size_t j = 0; j < targetAABBCount; j++)
			{
				_tempTargetAABB = { 0.0f, 0.0f, 0.0f, 0.0f };
				RB::Collisions::AABB& targetAABB = targetData->GetAABB(j);

				if (targetAABB.GetWidthHeight().x <= 0.001f || targetAABB.GetWidthHeight().y <= 0.001f)
				{
					continue;
				}

				olc::vi2d targetPos = target->GetPosition();
				RB::Collisions::AABB targetWorldAABB = targetAABB.GetWorldPos(target->GetPosition(), target->OtherPlayerIsOnRightSide());
				_tempTargetAABB = targetWorldAABB;

				if (ownerWorldAABB.IsCollidingAgainst(targetWorldAABB))
				{
					std::cout << "update count: " << _state->GetCumulatedFixedUpdates() << std::endl;
					std::cout << "player " << owner->GetPlayerID_int() << " hit player " << target->GetPlayerID_int() << std::endl;
					std::cout << std::endl;

					if (RB::Collisions::ATTACK_REGISTER_CONTROLLER->GetRegisteredAttackCount(target->GetPlayerID()) <= 0)
					{
						target->GetStateMachine()->OverrideNextState(new RB::PlayerStates::P0_Wince());
					}

					return;
				}
			}
		}
	}
}