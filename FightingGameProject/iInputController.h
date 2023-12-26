#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerT.h"

#include "PlayerID.h"
#include "PlayerInput.h"

#include "iInputObj.h"

namespace RB::Input
{
	class iInputController : public RB::Controllers::ControllerT<iInputController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual olc::HWButton GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputOBJ_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Special_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual iInputObj* GetUnused_Movement_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual bool IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) = 0;
		virtual size_t GetTotalInputCount(RB::Players::PlayerID playerID) = 0;
		virtual iInputObj* GetInputByIndex(RB::Players::PlayerID playerID, size_t index) = 0;
	};
}