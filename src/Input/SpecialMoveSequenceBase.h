#pragma once

#include <vector>

#include "PlayerInput.h"

#include "iSpecialMoveSequence.h"
#include "iInputController.h"

#include "../Players/PlayerType.h"

#include "../Players/iPlayerController.h"

namespace RB::Input
{
	class SpecialMoveSequenceBase : public iSpecialMoveSequence
	{
	public:
		SpecialMoveSequenceBase() = default;
		virtual ~SpecialMoveSequenceBase() override;

	public:
		virtual bool IsMatching(Players::PLAYER_TYPE playerID) override;
		virtual Input::SpecialMoveType GetSpecialMoveType() override;

	protected:
		void _SetSequence(SpecialMoveType specialMoveType, const std::vector<Input::PlayerInput>& vec);
		void _SetSequenceForRightSide(const std::vector<Input::PlayerInput>& vec);
		const std::vector<Input::PlayerInput>& _GetSequence(bool playerIsFacingRight);

		std::vector<Input::PlayerInput> _vecSequence;
		std::vector<Input::PlayerInput> _vecSequenceFromRightSide;
		SpecialMoveType _specialMoveType = Input::SpecialMoveType::NONE;
	};
}
