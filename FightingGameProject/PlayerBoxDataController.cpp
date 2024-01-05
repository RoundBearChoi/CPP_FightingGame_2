#include "PlayerBoxDataController.h"

#include "CharacterType.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/box_none_test.playerBoxSpecs", RB::Sprites::SpriteEnum::NONE, RB::Players::CharacterType::NONE);

		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_idle_box.playerBoxSpecs", RB::Sprites::SpriteEnum::aku_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_crouch_box.playerBoxSpecs", RB::Sprites::SpriteEnum::aku_crouch, RB::Players::CharacterType::AKU);
	}

	void PlayerBoxDataController::OnUpdate()
	{

	}

	void PlayerBoxDataController::OnFixedUpdate()
	{

	}

	LoadedPlayerBoxData* PlayerBoxDataController::GetLoadedData(RB::Players::CharacterType characterType)
	{
		return _playerBoxSpecsLoader.GetLoadedSpecs(characterType);
	}

	PlayerBoxSpecs* PlayerBoxDataController::AddSpecs(RB::Collisions::PlayerBoxSpecs specs)
	{
		return _playerBoxSpecsLoader.AddSpecs(specs);
	}
}