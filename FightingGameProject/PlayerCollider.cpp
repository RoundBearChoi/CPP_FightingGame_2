#include "PlayerCollider.h"

namespace RB::Players
{
	PlayerCollider::PlayerCollider()
	{

	}
	PlayerCollider::~PlayerCollider()
	{

	}
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
		iPlayer* otherPlayer = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetOtherPlayer(myID);
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

	void PlayerCollider::CheckCollision()
	{

	}
}