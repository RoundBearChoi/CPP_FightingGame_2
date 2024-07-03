#include "PlayerBoxDataController.h"

#include "CharacterType.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/box_none_test.playerBoxSpecs", RB::Sprites::SpriteType::NONE, RB::Players::CharacterType::NONE);

		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_idle_box.playerBoxSpecs", RB::Sprites::SpriteType::fighter_0_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_crouch_box.playerBoxSpecs", RB::Sprites::SpriteType::fighter_0_crouch, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_crouch_idle_box.playerBoxSpecs", RB::Sprites::SpriteType::aku_crouch_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_standup_box.playerBoxSpecs", RB::Sprites::SpriteType::aku_standup, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs("PlayerBoxSpecs/Aku/p0_jab_box.playerBoxSpecs", RB::Sprites::SpriteType::aku_jab, RB::Players::CharacterType::AKU);
	}

	void PlayerBoxDataController::OnUpdate()
	{
		_playerBoxSpecsLoader.OnUpdate();
	}

	void PlayerBoxDataController::OnFixedUpdate()
	{
		_playerBoxSpecsLoader.OnFixedUpdate();
	}

	LoadedPlayerBoxData* PlayerBoxDataController::GetLoadedData(RB::Players::CharacterType characterType)
	{
		return _playerBoxSpecsLoader.GetLoadedSpecs(characterType);
	}

	void PlayerBoxDataController::AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType)
	{
		_playerBoxSpecsLoader.AddSpecs(box, spriteType, characterType);
	}
}
