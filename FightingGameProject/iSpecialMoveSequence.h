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
		virtual bool IsMatching(RB::Players::PlayerID playerID) = 0;
		virtual RB::Input::SpecialMoveType GetSpecialMoveType() = 0;
	};
}