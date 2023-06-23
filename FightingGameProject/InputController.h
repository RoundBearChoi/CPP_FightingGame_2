#pragma once
#include <iostream>
#include "ControllerBase.h"
#include "KeyBinding.h"

#include "PlayerInput.h"
#include "PlayerID.h"

namespace RB::Input
{
	class InputController : public RB::Controllers::ControllerBase
	{
	public:
		InputController();
		~InputController() override;
		static inline InputController* PTR = nullptr;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		olc::HWButton GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput);

	private:
		std::vector<KeyBinding> _vecKeyBindings;
	};
}