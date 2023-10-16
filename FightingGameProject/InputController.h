#pragma once
#include <iostream>
#include "KeyBinding.h"

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

	private:
		void _AddInputBuffer();

		std::vector<KeyBinding> _vecKeyBindings;
		std::vector<iInputObj*> _vecInputObjs;
		size_t _totalInputTypes = 0;
	};
}