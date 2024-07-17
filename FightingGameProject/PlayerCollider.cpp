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

	}

	void PlayerCollider::OnFixedUpdate()
	{
		_UpdateBodyParts();

		_UpdateAABBOnPlayerPos();

		_ResolveCollision();
	}

	RB::Vector2 PlayerCollider::GetPlayerBox()
	{
		return RB::Vector2{ _playerBox.mWidth, _playerBox.mHeight };
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

	float* PlayerCollider::GetBodyParts()
	{
		return _bodyParts;
	}

	void PlayerCollider::_UpdateAABBOnPlayerPos()
	{
		RB::Vector2 bottomCenter = _player->GetPosition();
		RB::Vector2 playerBox = _player->GetPlayerCollider()->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		RB::Vector2 bottomLeft = bottomCenter - RB::Vector2{ halfWidth, 0.0f };

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

		RB::Vector2 col;

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

		RB::Vector2 otherPlayerPos = otherPlayer->GetPosition();
		RB::Vector2 myPos = _player->GetPosition();

		//if other player is in air and I'm on ground, I move away more quickly
		if (otherPlayerPos.y < -0.01f && myPos.y > -0.01f)
		{
			correction *= 2.0f;
		}

		if (myPos.x <= otherPlayerPos.x)
		{
			_player->Move(RB::Vector2{ -correction, 0.0f });
			otherPlayer->Move(RB::Vector2{ correction, 0.0f });
		}
		else
		{
			_player->Move(RB::Vector2{ correction, 0.0f });
			otherPlayer->Move(RB::Vector2{ -correction, 0.0f });
		}
	}

	void PlayerCollider::_UpdateBodyParts()
	{
		RB::Vector2 pos = _player->GetPosition();

		float lowerBodyLength = _playerBox.mHeight * _bodyRatio[0];
		float lowerBodyY = std::round(pos.y - lowerBodyLength);

		float upperBodyLength = _playerBox.mHeight * _bodyRatio[1];
		float upperBodyY = std::round(pos.y - upperBodyLength);

		_bodyParts[0] = lowerBodyY;
		_bodyParts[1] = upperBodyY;
	}
}
