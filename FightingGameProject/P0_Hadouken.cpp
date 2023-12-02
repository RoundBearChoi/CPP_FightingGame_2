#include "P0_Hadouken.h"

namespace RB::Input::Sequences
{
	P0_Hadouken::P0_Hadouken(RB::Input::SpecialMoveType specialMoveType, const std::vector<PlayerInput>& vec)
	{
		_SetSequence(specialMoveType, vec);
		_SetSequenceForRightSide(vec);
	}

	bool P0_Hadouken::IsMatching(RB::Players::PlayerID playerID)
	{
		return false;
	}
}