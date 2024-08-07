#pragma once

#include "../Input/PlayerInput.h"
#include "../States/StateComponentBase.h"

#include "../States/iState.h"
#include "../Players/iPlayerController.h"
#include "../Input/iInputController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnInput : public RB::States::StateComponentBase
	{
	public:
		TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input, bool useAsSpecial, bool useAsMovement);
		~TransitionOnInput() override {};

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;

	private:
		RB::Input::PlayerInput _input = RB::Input::PlayerInput::NONE;
		bool _useAsSpecial = false;
		bool _useAsMovement = false;
	};
}
