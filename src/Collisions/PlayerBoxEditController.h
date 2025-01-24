#pragma once

#include "PlayerBox.h"
#include "PlayerBoxSpecs.h"

#include "iPlayerBoxDataController.h"
#include "iPlayerBoxEditController.h"

#include "../Time.h"
#include "../Players/PlayerID.h"
#include "../Players/PlayerState.h"
#include "../Sprites/SpriteType.h"
#include "../Players/CharacterType.h"
#include "../Sprites/GetCurrentSpriteType.h"
#include "../Sprites/GetCurrentAnimationFrame.h"

#include "../Players/iPlayerController.h"
#include "../Render/iPlayerAnimationController.h"
#include "../Render/iPlayerDebugController.h"

namespace RB::Collisions
{
	class PlayerBoxEditController : public Collisions::iPlayerBoxEditController
	{
	public:
		PlayerBoxEditController() = default;
		~PlayerBoxEditController() override {}

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		void _UpdateBoxSizeOnPress(Collisions::PlayerBox* currentBox);
		void _AddDeleteBoxOnPress(Players::PlayerID id);
		void _SaveOnPress();
		void _ShowMenu();

	private:
		PlayerBox* _GetCurrentBox(Players::PlayerID id);
		PlayerBoxSpecs* _GetCurrentSpecs(Players::PlayerID id);
		Players::CharacterType _GetCharacterType(Players::PlayerID id);
	};
}