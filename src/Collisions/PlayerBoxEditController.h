#pragma once

#include "PlayerBox.h"
#include "PlayerBoxSpecs.h"

#include "iPlayerBoxDataController.h"
#include "iPlayerBoxEditController.h"

#include "../Time.h"
#include "../Players/PlayerID.h"
#include "../Players/PlayerState.h"
#include "../SpriteType.h"
#include "../Players/CharacterType.h"
#include "../GetCurrentSpriteType.h"
#include "../Sprites/GetCurrentAnimationFrame.h"

#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"
#include "../Render/iPlayerDebugController.h"

namespace RB::Collisions
{
	class PlayerBoxEditController : public RB::Collisions::iPlayerBoxEditController
	{
	public:
		PlayerBoxEditController() = default;
		~PlayerBoxEditController() override {}

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		void _UpdateBoxSizeOnPress(RB::Collisions::PlayerBox* currentBox);
		void _AddDeleteBoxOnPress(RB::Players::PlayerID id);
		void _SaveOnPress();
		void _ShowMenu();

	private:
		PlayerBox* _GetCurrentBox(RB::Players::PlayerID id);
		PlayerBoxSpecs* _GetCurrentSpecs(RB::Players::PlayerID id);
		RB::Players::CharacterType _GetCharacterType(RB::Players::PlayerID id);
	};
}
