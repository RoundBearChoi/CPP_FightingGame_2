#pragma once

#include "iPlayerBoxEditController.h"

#include "PlayerBox.h"
#include "PlayerBoxSpecs.h"
#include "PlayerID.h"
#include "SpriteType.h"
#include "CharacterType.h"

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
		RB::Sprites::SpriteType _GetCurrentSpriteType(RB::Players::PlayerID id);
		unsigned int _GetCurrentFrame(RB::Players::PlayerID id);
	};
}