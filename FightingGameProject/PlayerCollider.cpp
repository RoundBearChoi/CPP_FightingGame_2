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
}