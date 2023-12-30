#include "PlayerCollider.h"

namespace RB::Players
{
	void PlayerCollider::Init(iPlayer* owner)
	{
		_player = owner;
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

	olc::vi2d PlayerCollider::GetPlayerBox()
	{
		return _playerBox;
	}

	bool PlayerCollider::IsCollidingAgainstOtherPlayer()
	{
		return _isCollidingAgainstOtherPlayer;
	}

	RB::Collisions::AABB& PlayerCollider::GetAABB()
	{
		return _aabb;
	}

	RB::Collisions::AABB& PlayerCollider::_UpdateAABBOnPlayerPos()
	{
		olc::vi2d bottomCenter = _player->GetPosition();
		olc::vi2d playerBox = _player->GetPlayerCollider()->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		olc::vf2d bottomLeft = bottomCenter - olc::vf2d{ halfWidth, 0.0f };

		_aabb.SetBottomLeft(bottomLeft.x, bottomLeft.y);
		_aabb.SetWidthHeight((float)playerBox.x, (float)playerBox.y);

		return _aabb;
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

		RB::Collisions::AABB& otherAABB = other->GetPlayerCollider()->GetAABB();
		RB::Collisions::AABB& myAABB = _aabb;

		olc::vf2d col;

		if (myAABB.IsCollidingAgainst(otherAABB, col))
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
		int correction = 2;

		olc::vi2d otherPlayerPos = otherPlayer->GetPosition();
		olc::vi2d myPos = _player->GetPosition();

		//if other player is in air and I'm on ground, I move away more quickly
		if (otherPlayerPos.y < -0.01f && myPos.y > -0.01f)
		{
			correction *= 2;
		}

		if (myPos.x <= otherPlayerPos.x)
		{
			_player->Move(olc::vi2d{ -correction, 0 });
			otherPlayer->Move(olc::vi2d{ correction, 0 });
		}
		else
		{
			_player->Move(olc::vi2d{ correction, 0 });
			otherPlayer->Move(olc::vi2d{ -correction, 0 });
		}
	}
}