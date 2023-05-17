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
		if (_playerController == nullptr)
		{
			_playerController = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
			return;
		}
	}

	void PlayerCollider::OnFixedUpdate()
	{
		if (_playerController == nullptr)
		{
			return;
		}

		PlayerID myID = _player->GetPlayerID();
		iPlayer* other = _playerController->GetOtherPlayer(_player);

		if (other == nullptr)
		{
			return;
		}

		RB::Collisions::AABB otherAABB = other->GetAABB();
		RB::Collisions::AABB myAABB = GetAABB();

		if (myAABB.IsCollidingAgainst(otherAABB))
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

	const RB::Collisions::AABB& PlayerCollider::GetAABB()
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

		if (_player->GetPosition().x <= otherPlayer->GetPosition().x)
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