#pragma once

#include "../Players/iPlayer.h"
#include "../Players/iPlayerController.h"
#include "../States/StateComponentBase.h"

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
		Players::iPlayer* _player = nullptr;
	};
}
