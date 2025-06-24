#pragma once

#include "../olcPixelGameEngine.h"

#include "PlayerInput.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/PlayerID.h"

#include "iInputObj.h"

namespace RB::Input
{
	#define GET_INPUT_CONTROLLER static_cast<Input::iInputController*>(Controllers::GetController(Controllers::ControllerType::INPUT_CONTROLLER))

	class iInputController : public RB::Controllers::ControllerBase
	{
	public:
		virtual olc::HWButton GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputObj_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Special_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Movement_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual bool IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual const std::vector<iInputObj*>& GetVecInputObjs(RB::Players::PlayerID playerID) = 0;
		virtual iInputObj* GetInputByIndex(RB::Players::PlayerID playerID, unsigned int index) = 0;
	};
}
