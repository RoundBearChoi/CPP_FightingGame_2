#pragma once

#include "SpecialMoveSequenceBase.h"

namespace RB::Input::Sequences
{
	class P0_Hadouken : public SpecialMoveSequenceBase
	{
	public:
		P0_Hadouken(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size);
	};
}