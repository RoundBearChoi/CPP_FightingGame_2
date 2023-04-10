#pragma once
#include "iInputController.h"
#include "PlayerInput.h"

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
		olc::HWButton GetButton(Input::PlayerInput playerInput) override;
	};
}