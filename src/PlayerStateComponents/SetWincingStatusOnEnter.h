#pragma once

#include "../Players/iPlayer.h"
#include "../Players/iPlayerController.h"

#include "../States/StateComponentBase.h"

namespace RB::PlayerStateComponents
{
	class SetWincingStatusOnEnter : public RB::States::StateComponentBase
	{
	public:
		SetWincingStatusOnEnter(bool fix);
		~SetWincingStatusOnEnter() override {};

	public:
		void OnEnter() override;
		void OnExit() override;

	private:
		bool _fix = false;
		RB::Players::iPlayer* _player = nullptr;
	};
}