#pragma once
#include "StateComponentBase.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class FixDirectionDuringState : public RB::States::StateComponentBase
	{
	public:
		FixDirectionDuringState(bool fix);
		~FixDirectionDuringState() override {};

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		bool _fix = false;
		RB::Players::iPlayer* _player = nullptr;
	};
}