#include "PlayerCollider.h"

namespace RB::Players
{
	void PlayerCollider::Init(iPlayer* owner)
	{
		_player = owner;

		_playerBox.mWidth = 62.0f;
		_playerBox.mHeight = 124.0f;
	}

	void PlayerCollider::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}
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
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		PlayerID myID = _player->GetPlayerID();
		iPlayer* other = RB::Players::iPlayerController::instance->GetOtherPlayer(_player);

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
}