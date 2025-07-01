#include "P0_Seq_Hadouken.h"

namespace RB::Input::Sequences
{
	P0_Seq_Hadouken::P0_Seq_Hadouken(Input::SpecialMoveType specialMoveType, const std::vector<PlayerInput>& vec)
	{
		_SetSequence(specialMoveType, vec);
		_SetSequenceForRightSide(vec);
	}
}
