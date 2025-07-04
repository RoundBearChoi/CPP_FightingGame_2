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
		TransitionOnInput(RB::States::iState* nextState, Input::PlayerInput input, Input::InputType inputType);
		~TransitionOnInput() override {};

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;

	private:
		Input::PlayerInput _input = Input::PlayerInput::NONE;
		Input::InputType _inputType = Input::InputType::NONE;
	};
}
