#pragma once
#include <iostream>
#include "CurrentInputController.h"
#include "iInputController.h"
#include "PlayerInput.h"
#include "PlayerID.h"
#include "KeyBinding.h"

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

	public:
		olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput) override;

	private:
		std::vector<KeyBinding> _vecKeyBindings;
	};
}