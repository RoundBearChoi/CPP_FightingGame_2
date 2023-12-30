#include "PlayerBoxDataController.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_idle_box.playerBoxSpecs", RB::Sprites::SpriteEnum::aku_idle);
	}

	void PlayerBoxDataController::OnUpdate()
	{

	}

	void PlayerBoxDataController::OnFixedUpdate()
	{

	}
}