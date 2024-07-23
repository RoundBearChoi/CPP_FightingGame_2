#pragma once

#include <vector>

#include "Players/PlayerID.h"
#include "PlayerInput.h"

#include "iSpecialMoveSequence.h"
#include "Players/iPlayerController.h"
#include "Input/iInputController.h"

namespace RB::Input
{
	class SpecialMoveSequenceBase : public iSpecialMoveSequence
	{
	public:
		SpecialMoveSequenceBase() = default;
		virtual ~SpecialMoveSequenceBase() override;

	public:
		virtual bool IsMatching(RB::Players::PlayerID playerID) override;
		virtual RB::Input::SpecialMoveType GetSpecialMoveType() override;

	protected:
		void _SetSequence(SpecialMoveType specialMoveType, const std::vector<RB::Input::PlayerInput>& vec);
		void _SetSequenceForRightSide(const std::vector<RB::Input::PlayerInput>& vec);
		const std::vector<RB::Input::PlayerInput>& _GetSequence(bool playerIsFacingRight);

		std::vector<RB::Input::PlayerInput> _vecSequence;
		std::vector<RB::Input::PlayerInput> _vecSequenceFromRightSide;
		SpecialMoveType _specialMoveType = RB::Input::SpecialMoveType::NONE;
	};
}
