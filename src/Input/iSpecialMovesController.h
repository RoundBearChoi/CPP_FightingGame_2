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
		virtual Input::SpecialMoveType GetSpecialMove(Players::PlayerID playerID) = 0;
		virtual States::iState* GetNewState(Input::SpecialMoveType specialMoveType) = 0;
	};
}
