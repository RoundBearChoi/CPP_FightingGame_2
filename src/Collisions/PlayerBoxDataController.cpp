#include "PlayerBoxDataController.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		_playerBoxSpecsLoader.LoadSpecs(RB::Sprites::SpriteType::fighter_0_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(RB::Sprites::SpriteType::fighter_0_crouch, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(RB::Sprites::SpriteType::fighter_0_crouch_idle, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(RB::Sprites::SpriteType::fighter_0_standup, RB::Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(RB::Sprites::SpriteType::fighter_0_jab, RB::Players::CharacterType::AKU);
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