#pragma once

#include "SpecialMoveType.h"

#include "../Players/PlayerType.h"

namespace RB::Input
{
	class iSpecialMoveSequence
	{
	public:
		virtual ~iSpecialMoveSequence() = default;

	public:
		virtual bool IsMatching(Players::PLAYER_TYPE playerID) = 0;
		virtual Input::SpecialMoveType GetSpecialMoveType() = 0;
	};
}
