#include "PlayerCollision.h"

namespace RB::Players
{
	PlayerCollision::PlayerCollision()
	{

	}
	PlayerCollision::~PlayerCollision()
	{

	}
	void PlayerCollision::Init(iPlayer* owner)
	{
		_player = owner;
	}
}