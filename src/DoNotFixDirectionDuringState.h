#pragma once

#include "Players/iPlayer.h"

#include "StateComponentBase.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class DoNotFixDirectionDuringState : public RB::States::StateComponentBase
	{
	public:
		DoNotFixDirectionDuringState() = default;
		~DoNotFixDirectionDuringState() override {};

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		RB::Players::iPlayer* _player = nullptr;
	};
}
