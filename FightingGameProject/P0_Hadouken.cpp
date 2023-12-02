#include "P0_Hadouken.h"

namespace RB::Input::Sequences
{
	P0_Hadouken::P0_Hadouken(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size)
	{
		_specialMoveType = specialMoveType;

		for (size_t i = 0; i < size; i++)
		{
			_vecSequence.push_back(arr[i]);
		}
	}
}