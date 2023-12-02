#include "P0_Hadouken.h"

namespace RB::Input::Sequences
{
	P0_Hadouken::P0_Hadouken(RB::Input::SpecialMoveType specialMoveType, const std::vector<PlayerInput>& vec)
	{
		_specialMoveType = specialMoveType;

		for (size_t i = 0; i < vec.size(); i++)
		{
			_vecSequence.push_back(vec[i]);
		}
	}
}