#pragma once
#include "StateComponentBase.h"
#include "P0_JumpUp.h"
#include "CurrentControllers.h"
#include "InputController.h"

namespace RB::PlayerStateComponents
{
	class TriggerJumpUp : public RB::States::StateComponentBase
	{
	public:
		TriggerJumpUp() = default;
		~TriggerJumpUp() override {};

		public:
			void OnEnter() override;
			void OnUpdate() override;

	private:
		RB::Input::InputController* _inputController = nullptr;
	};
}