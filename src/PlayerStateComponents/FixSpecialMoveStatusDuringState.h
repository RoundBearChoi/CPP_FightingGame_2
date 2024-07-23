#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayer.h"

#include "../Players/iPlayerController.h"

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
