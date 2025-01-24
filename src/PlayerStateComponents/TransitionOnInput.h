#pragma once

#include "../Input/iInputController.h"
#include "../Input/PlayerInput.h"
#include "../Input/InputType.h"

#include "../States/StateComponentBase.h"
#include "../States/iState.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnInput : public RB::States::StateComponentBase
	{
	public:
		TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input, RB::Input::InputType inputType);
		~TransitionOnInput() override {};

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;

	private:
		RB::Input::PlayerInput _input = RB::Input::PlayerInput::NONE;
		RB::Input::InputType _inputType = RB::Input::InputType::NONE;
	};
}