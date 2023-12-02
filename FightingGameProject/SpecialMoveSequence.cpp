#include "SpecialMoveSequence.h"

namespace RB::Input
{
	SpecialMoveSequence::~SpecialMoveSequence()
	{

	}

	void SpecialMoveSequence::Init(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size)
	{
		_specialMoveType = specialMoveType;

		for (size_t i = 0; i < size; i++)
		{
			_vecSequence.push_back(arr[i]);
		}
	}

	bool SpecialMoveSequence::IsAMatch(RB::Players::PlayerID playerID)
	{
	
	
	
	
		return false;
	}
}