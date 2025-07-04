#pragma once

#include "../olcPixelGameEngine.h"

#include "PlayerInput.h"

#include "../Controllers/ControllerBase.h"
#include "../Players/PlayerType.h"

#include "iInputObj.h"

namespace RB::Input
{
	#define GET_INPUT_CONTROLLER static_cast<Input::iInputController*>(Controllers::GetController(Controllers::ControllerType::INPUT_CONTROLLER))

	class iInputController : public Controllers::ControllerBase
	{
	public:
		virtual olc::HWButton GetKeyBinding(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputObj_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputObj_LIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Special_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Movement_FIFO(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual bool IsHeld(Players::PLAYER_TYPE playerID, Input::PlayerInput playerInput) = 0;
		virtual const std::vector<iInputObj*>& GetVecInputObjs(Players::PLAYER_TYPE playerID) = 0;
		virtual iInputObj* GetInputByIndex(Players::PLAYER_TYPE playerID, unsigned int index) = 0;
	};
}
