#include "PlayerCollider.h"

#include <cmath>

#include "iCamController.h"

namespace RB::Players
{
	void PlayerCollider::Init(iPlayer* owner)
	{
		_player = owner;

		_playerBox.mWidth = 62.0f;
		_playerBox.mHeight = 124.0f;

		_bodyRatio[0] = 0.3f;
		_bodyRatio[1] = 0.8f;
	}

	void PlayerCollider::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		//temp
		_UpdateBodyParts();
	}

	void PlayerCollider::OnFixedUpdate()
	{
		

		_UpdateAABBOnPlayerPos();

		_ResolveCollision();
	}

	olc::vf2d PlayerCollider::GetPlayerBox()
	{
		return olc::vf2d{ _playerBox.mWidth, _playerBox.mHeight };
	}

	void PlayerCollider::SetPlayerBox(const RB::Collisions::PlayerBox& box)
	{
		_playerBox.mOffsetX = box.mOffsetX;
		_playerBox.mOffsetX = box.mOffsetY;
		_playerBox.mWidth = box.mWidth;
		_playerBox.mHeight = box.mHeight;
	}

	bool PlayerCollider::IsCollidingAgainstOtherPlayer()
	{
		return _isCollidingAgainstOtherPlayer;
	}

	const RB::Collisions::AABB& PlayerCollider::GetAABB()
	{
		return _aabb;
	}

	RB::Collisions::AABB* PlayerCollider::GetAABB_ptr()
	{
		return &_aabb;
	}

	void PlayerCollider::_UpdateAABBOnPlayerPos()
	{
		olc::vf2d bottomCenter = _player->GetPosition();
		olc::vf2d playerBox = _player->GetPlayerCollider()->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		olc::vf2d bottomLeft = bottomCenter - olc::vf2d{ halfWidth, 0.0f };

		_aabb.SetBottomLeft(bottomLeft.x, bottomLeft.y);
		_aabb.SetWidthHeight(playerBox.x, playerBox.y);
	}

	void PlayerCollider::_ResolveCollision()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		PlayerID myID = _player->GetPlayerID();
		iPlayer* other = RB::Players::iPlayerController::Get()->GetOtherPlayer(_player);

		if (other == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* otherAABB = other->GetPlayerCollider()->GetAABB_ptr();
		RB::Collisions::AABB* myAABB = &_aabb;

		olc::vf2d col;

		if (myAABB->IsCollidingAgainst(*otherAABB, col))
		{
			_isCollidingAgainstOtherPlayer = true;

			_MovePlayers(other);
		}
		else
		{
			_isCollidingAgainstOtherPlayer = false;
		}
	}

	void PlayerCollider::_MovePlayers(iPlayer* otherPlayer)
	{
		float correction = 2.5;

		olc::vf2d otherPlayerPos = otherPlayer->GetPosition();
		olc::vf2d myPos = _player->GetPosition();

		//if other player is in air and I'm on ground, I move away more quickly
		if (otherPlayerPos.y < -0.01f && myPos.y > -0.01f)
		{
			correction *= 2.0f;
		}

		if (myPos.x <= otherPlayerPos.x)
		{
			_player->Move(olc::vf2d{ -correction, 0.0f });
			otherPlayer->Move(olc::vf2d{ correction, 0.0f });
		}
		else
		{
			_player->Move(olc::vf2d{ correction, 0.0f });
			otherPlayer->Move(olc::vf2d{ -correction, 0.0f });
		}
	}

	void PlayerCollider::_UpdateBodyParts()
	{
		olc::vf2d pos = _player->GetPosition();

		float lowerBodyLength = _playerBox.mHeight * _bodyRatio[0];
		float lowerBodyY = std::round(pos.y - lowerBodyLength);

		float upperBodyLength = _playerBox.mHeight * _bodyRatio[1];
		float upperBodyY = std::round(pos.y - upperBodyLength);

		_bodyParts[0] = lowerBodyY;
		_bodyParts[1] = upperBodyY;

		olc::vf2d relLowerBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ pos.x, _bodyParts[0] });
		olc::vi2d intLowerBody = { int(round(relLowerBody.x)), int(round(relLowerBody.y)) };

		olc::vf2d relUpperBody = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition({ pos.x, _bodyParts[1] });
		olc::vi2d intUpperBody = { int(round(relUpperBody.x)), int(round(relUpperBody.y)) };

		olc::Renderer::ptrPGE->SetDrawTarget(nullptr);

		int lineHalfLength = 50;

		olc::Renderer::ptrPGE->DrawLine(intLowerBody - olc::vi2d{ lineHalfLength, 0 }, intLowerBody + olc::vi2d{ lineHalfLength, 0 }, olc::RED);
		olc::Renderer::ptrPGE->DrawLine(intUpperBody - olc::vi2d{ lineHalfLength, 0 }, intUpperBody + olc::vi2d{ lineHalfLength, 0 }, olc::RED);
	}
}
