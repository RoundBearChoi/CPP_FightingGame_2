#pragma once

#include "SpecialMoveType.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/PlayerID.h"

#include "../States/iState.h"

namespace RB::Input
{
	#define GET_SPECIAL_MOVES_CONTROLLER static_cast<Input::iSpecialMovesController*>(Controllers::GetController(Controllers::ControllerType::SPECIAL_MOVES_CONTROLLER))

	class iSpecialMovesController : public Controllers::ControllerBase
	{
	public:
		virtual RB::Input::SpecialMoveType GetSpecialMove(RB::Players::PlayerID playerID) = 0;
		virtual RB::States::iState* GetNewState(RB::Input::SpecialMoveType specialMoveType) = 0;
	};
}