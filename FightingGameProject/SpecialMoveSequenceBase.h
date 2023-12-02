#pragma once

#include <vector>

#include "iSpecialMoveSequence.h"

namespace RB::Input
{
	class SpecialMoveSequenceBase : public iSpecialMoveSequence
	{
	public:
		SpecialMoveSequenceBase() = default;
		virtual ~SpecialMoveSequenceBase() override;

	public:
		virtual void Init(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size) override;

		virtual bool IsAMatch(RB::Players::PlayerID playerID) override;

	protected:
		std::vector<RB::Input::PlayerInput> _vecSequence;
		std::vector<RB::Input::PlayerInput> _vecSequenceFromRightSide;
		SpecialMoveType _specialMoveType = RB::Input::SpecialMoveType::NONE;
	};
}