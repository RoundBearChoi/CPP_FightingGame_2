#pragma once

#include "SpecialMoveType.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/PlayerID.h"

#include "../States/iState.h"

namespace RB::Input
{
	#define GET_SPECIAL_MOVES_CONTROLLER static_cast<RB::Input::iSpecialMovesController*>(RB::Controllers::GetController(Controllers::ControllerType::SPECIAL_MOVES_CONTROLLER))

	class iSpecialMovesController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
		virtual RB::Input::SpecialMoveType GetSpecialMove(RB::Players::PlayerID playerID) = 0;
		virtual RB::States::iState* GetNewState(RB::Input::SpecialMoveType specialMoveType) = 0;
	};
}