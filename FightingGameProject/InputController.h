#pragma once
#include <iostream>
#include "KeyBinding.h"
#include "GameFrame.h"

#include "iInputController.h"
#include "iInputObj.h"
#include "InputObj.h"

namespace RB::Input
{
	class InputController : public iInputController
	{
	public:
		InputController();
		~InputController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		olc::HWButton GetKeyBinding(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputOBJ_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetInputObj_LIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		iInputObj* GetUnusedInputObj_FIFO(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		bool IsHeld(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;
		size_t GetTotalInputCount(RB::Players::PlayerID playerID) override;
		iInputObj* GetInputByIndex(RB::Players::PlayerID playerID, size_t index) override;

	private:
		void _UpdateInputBuffer(RB::Players::PlayerID playerID);
		void _AddNewInputBuffer(RB::Players::PlayerID playerID, PlayerInput input);
		void _UpdateReleaseStatus(RB::Players::PlayerID playerID, PlayerInput input);
		void _UpdateDiagBuffer(RB::Players::PlayerID playerID);
		void _DestroyOldBuffers(RB::Players::PlayerID playerID);
		void _ClearAllBuffers(RB::Players::PlayerID playerID);
		std::vector<iInputObj*>& _GetInputObjs(RB::Players::PlayerID playerID);

		std::vector<KeyBinding> _vecKeyBindings;
		std::vector<iInputObj*> _vecNone;
		std::vector<iInputObj*> _vecP1_InputObjs;
		std::vector<iInputObj*> _vecP2_InputObjs;
		size_t _totalInputTypes = 0;
	};
}