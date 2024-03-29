#pragma once

#include <vector>

#include "SpecialMoveSequenceBase.h"
#include "PlayerInput.h"

namespace RB::Input::Sequences
{
	class P0_Seq_Hadouken : public SpecialMoveSequenceBase
	{
	public:
		P0_Seq_Hadouken(RB::Input::SpecialMoveType specialMoveType, const std::vector<PlayerInput>& vec);
	};
}