#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MarkCrouchingOnEnter : public RB::States::StateComponentBase
	{
	public:
		MarkCrouchingOnEnter(bool crouching);
		~MarkCrouchingOnEnter() override = default;

		void OnEnter() override;

	private:
		bool _crouching = true;
	};
}