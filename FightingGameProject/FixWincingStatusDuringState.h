#pragma once
#include "StateComponentBase.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class FixWincingStatusDuringState : public RB::States::StateComponentBase
	{
	public:
		FixWincingStatusDuringState(bool fix);
		~FixWincingStatusDuringState() override {};

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		bool _fix = false;
		RB::Players::iPlayer* _player = nullptr;
	};
}