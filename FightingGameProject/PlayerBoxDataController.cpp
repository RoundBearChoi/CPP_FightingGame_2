#include "PlayerBoxDataController.h"

#include "CharacterType.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/none_idle_box (test).playerBoxSpecs", RB::Sprites::SpriteEnum::aku_idle, RB::Players::CharacterType::NONE);

		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_idle_box.playerBoxSpecs", RB::Sprites::SpriteEnum::aku_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_crouch_box.playerBoxSpecs", RB::Sprites::SpriteEnum::aku_crouch, RB::Players::CharacterType::AKU);

	}

	void PlayerBoxDataController::OnUpdate()
	{

	}

	void PlayerBoxDataController::OnFixedUpdate()
	{

	}

	LoadedPlayerBoxSpecs* PlayerBoxDataController::GetPlayerBoxSpecs(RB::Players::CharacterType characterType)
	{
		return _playerBoxSpecsLoader.GetLoadedSpecs(characterType);
	}
}