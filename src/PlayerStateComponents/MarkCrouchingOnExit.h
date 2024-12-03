#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MarkCrouchingOnExit : public RB::States::StateComponentBase
	{
	public:
		MarkCrouchingOnExit(bool crouching);
		~MarkCrouchingOnExit() override = default;

		void OnExit() override;

	private:
		bool _crouching = true;
	};
}