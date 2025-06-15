#include "PlayerBoxDataController.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		//INIT_CONTROLLER
		
		_playerBoxSpecsLoader.LoadSpecs(Sprites::SpriteType::fighter_0_idle, Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(Sprites::SpriteType::fighter_0_crouch, Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(Sprites::SpriteType::fighter_0_crouch_idle, Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(Sprites::SpriteType::fighter_0_standup, Players::CharacterType::AKU);
		_playerBoxSpecsLoader.LoadSpecs(Sprites::SpriteType::fighter_0_jab, Players::CharacterType::AKU);
	}

	void PlayerBoxDataController::OnUpdate()
	{
		_playerBoxSpecsLoader.OnUpdate();
	}

	void PlayerBoxDataController::OnFixedUpdate()
	{
		_playerBoxSpecsLoader.OnFixedUpdate();
	}

	LoadedPlayerBoxData* PlayerBoxDataController::GetLoadedData(Players::CharacterType characterType)
	{
		return _playerBoxSpecsLoader.GetLoadedSpecs(characterType);
	}

	void PlayerBoxDataController::AddSpecs(PlayerBox box, Sprites::SpriteType spriteType, Players::CharacterType characterType)
	{
		_playerBoxSpecsLoader.AddSpecs(box, spriteType, characterType);
	}
}
