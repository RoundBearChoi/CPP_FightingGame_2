#pragma once

#include <vector>

#include "iSpecialMoveSequence.h"

namespace RB::Input
{
	class SpecialMoveSequence : public iSpecialMoveSequence
	{
	public:
		SpecialMoveSequence() = default;
		~SpecialMoveSequence() override;

	public:
		void Init(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size) override;

		bool IsAMatch(RB::Players::PlayerID playerID) override;

	private:
		std::vector<RB::Input::PlayerInput> _vecSequence;
		std::vector<RB::Input::PlayerInput> _vecSequenceFromRightSide;
		SpecialMoveType _specialMoveType = RB::Input::SpecialMoveType::NONE;
	};
}