#pragma once

#include "StateComponentBase.h"

#include "Players/iPlayer.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class FixSpecialMoveStatusDuringState : public RB::States::StateComponentBase
	{
	public:
		FixSpecialMoveStatusDuringState(bool fix);
		~FixSpecialMoveStatusDuringState() override {};

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		bool _fix = false;
		RB::Players::iPlayer* _player = nullptr;
	};
}
