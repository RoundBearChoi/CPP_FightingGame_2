#pragma once

#include "PlayerBoxSpecsLoader.h"

#include "iPlayerBoxDataController.h"

#include "../Sprites/SpriteType.h"
#include "../Players/CharacterType.h"

namespace RB::Collisions
{
	class PlayerBoxDataController : public iPlayerBoxDataController
	{
	public:
			PlayerBoxDataController() = default;
			~PlayerBoxDataController() override {}

	public:
			void Init() override;
			void OnUpdate() override;
			void OnFixedUpdate() override;

			LoadedPlayerBoxData* GetLoadedData(RB::Players::CharacterType characterType) override;
			void AddSpecs(PlayerBox box, RB::Sprites::SpriteType spriteType, RB::Players::CharacterType characterType) override;

	private:
		PlayerBoxSpecsLoader _playerBoxSpecsLoader;
	};
}
