#pragma once
#include <iostream>
#include "KeyBinding.h"

#include "iInputController.h"

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

		olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput);

	private:
		std::vector<KeyBinding> _vecKeyBindings;
	};
}