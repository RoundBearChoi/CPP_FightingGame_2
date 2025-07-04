#include "PlayerBoxDataController.h"

#include "../Logger/iLogController.h"

namespace RB::Collisions
{
	void PlayerBoxDataController::Init()
	{
		auto logController = GET_LOG_CONTROLLER;

		logController->AddToStream(Players::PLAYER_TYPE::NONE, Log::LOG_TYPE::LOAD_JSON, "loading player boxes"); 

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
