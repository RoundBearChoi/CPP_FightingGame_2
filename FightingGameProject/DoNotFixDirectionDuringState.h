#pragma once
#include "StateComponentBase.h"

#include "iPlayer.h"

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