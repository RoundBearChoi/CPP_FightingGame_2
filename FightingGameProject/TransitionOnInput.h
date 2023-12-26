#pragma once
#include "StateComponentBase.h"
#include "P0_Jab.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "iInputController.h"

namespace RB::PlayerStateComponents
{
	class TransitionOnInput : public RB::States::StateComponentBase
	{
	public:
		TransitionOnInput(RB::States::iState* nextState, RB::Input::PlayerInput input, bool useAsSpecial, bool useAsMovement);
		~TransitionOnInput() override;

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