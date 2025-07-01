#pragma once

#include "SpecialMoveType.h"

#include "../Players/PlayerID.h"

namespace RB::Input
{
	class iSpecialMoveSequence
	{
	public:
		virtual ~iSpecialMoveSequence() = default;

	public:
		virtual bool IsMatching(Players::PlayerID playerID) = 0;
		virtual Input::SpecialMoveType GetSpecialMoveType() = 0;
	};
}
