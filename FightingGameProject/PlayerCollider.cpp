#include "PlayerCollider.h"

namespace RB::Players
{
	void PlayerCollider::Init(iPlayer* owner)
	{
		_player = owner;
	}

	void PlayerCollider::OnUpdate()
	{

	}

	void PlayerCollider::OnFixedUpdate()
	{
		PlayerID myID = _player->GetPlayerID();
		iPlayer* otherPlayer = _player->GetOtherPlayer();

		RB::Collisions::AABB otherAABB = otherPlayer->GetAABB();
		RB::Collisions::AABB myAABB = GetAABB();

		if (myAABB.IsCollidingAgainst(otherAABB))
		{
			_isColliding = true;

			ResolveCollision(otherPlayer);
		}
		else
		{
			_isColliding = false;
		}
	}

	RB::Collisions::AABB PlayerCollider::GetAABB()
	{
		olc::vi2d bottomCenter = _player->GetPosition();
		olc::vi2d playerBox = _player->GetPlayerBox();
		float halfWidth = playerBox.x * 0.5f;

		olc::vf2d bottomLeft = bottomCenter - olc::vf2d{ halfWidth, 0.0f };

		return RB::Collisions::AABB{ (float)bottomLeft.x, (float)bottomLeft.y, (float)playerBox.x, (float)playerBox.y };
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