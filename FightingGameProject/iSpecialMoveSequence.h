#pragma once

#include "PlayerID.h"
#include "PlayerInput.h"
#include "SpecialMoveType.h"

namespace RB::Input
{
	class iSpecialMoveSequence
	{
	public:
		virtual ~iSpecialMoveSequence() = default;

	public:
		//virtual void Init(RB::Input::SpecialMoveType specialMoveType, RB::Input::PlayerInput* arr, size_t size) = 0;

		virtual bool IsAMatch(RB::Players::PlayerID playerID) = 0;
	};
}