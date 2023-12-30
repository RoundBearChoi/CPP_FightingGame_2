#pragma once

#include "PlayerBoxSpecsLoader.h"
#include "CharacterType.h"

#include "iPlayerBoxDataController.h"

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

			LoadedPlayerBoxSpecs* GetLoadedSpecs(RB::Players::CharacterType characterType) override;

	private:
		PlayerBoxSpecsLoader _playerBoxSpecsLoader;
	};
}