#include "PlayerCollider.h"

namespace RB::Players
{
	void PlayerCollider::Init(iPlayer* owner)
	{
		_player = owner;

		InitPlayerColliderAABB();
	}

	void PlayerCollider::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}
	}

	void PlayerCollider::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		PlayerID myID = _player->GetPlayerID();
		iPlayer* other = RB::Players::PLAYER_CONTROLLER->GetOtherPlayer(_player);

		if (other == nullptr)
		{
			return;
		}

		RB::Collisions::AABB otherAABB = other->UpdateAABBOnPlayerPos();
		RB::Collisions::AABB myAABB = UpdateAABBOnPlayerPos();

		olc::vf2d col;

		if (myAABB.IsCollidingAgainst(otherAABB, col))
		{
			_isColliding = true;

			ResolveCollision(other);
		}
		else
		{
			_isColliding = false;
		}
	}

	void PlayerCollider::InitPlayerColliderAABB()
	{
		olc::vi2d bottomCenter = _player->GetPosition();
		olc::vi2d playerBox = _player->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		olc::vf2d bottomLeft = bottomCenter - olc::vf2d{ halfWidth, 0.0f };

		_aabb = RB::Collisions::AABB{ (float)bottomLeft.x, (float)bottomLeft.y, (float)playerBox.x, (float)playerBox.y };
	}

	RB::Collisions::AABB& PlayerCollider::UpdateAABBOnPlayerPos()
	{
		olc::vi2d bottomCenter = _player->GetPosition();
		olc::vi2d playerBox = _player->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		olc::vf2d bottomLeft = bottomCenter - olc::vf2d{ halfWidth, 0.0f };

		_aabb.SetBottomLeft(bottomLeft.x, bottomLeft.y);

		return _aabb;
	}

	olc::vi2d PlayerCollider::GetPlayerBox()
	{
		return _playerBox;
	}

	bool PlayerCollider::IsColliding()
	{
		return _isColliding;
	}

	void PlayerCollider::ResolveCollision(iPlayer* otherPlayer)
	{
		int moveCorrectionAmount = 2;

		olc::vi2d otherPlayerPos = otherPlayer->GetPosition();
		olc::vi2d myPos = _player->GetPosition();

		if (otherPlayerPos.y < -0.01f && myPos.y > -0.01f)
		{
			moveCorrectionAmount *= 2.0f;
		}

		if (myPos.x <= otherPlayerPos.x)
		{
			_player->Move(olc::vi2d{ -moveCorrectionAmount, 0 });
			otherPlayer->Move(olc::vi2d{ moveCorrectionAmount, 0 });
		}
		else
		{
			_player->Move(olc::vi2d{ moveCorrectionAmount, 0 });
			otherPlayer->Move(olc::vi2d{ -moveCorrectionAmount, 0 });
		}
	}
}