#pragma once
#include <cstdint>
#include "StateComponentBase.h"

#include "iPlayer.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveHorizontalOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		MoveHorizontalOnFixedUpdateCount(int32_t fixedUpdateOnCount, bool forward, int32_t move);
		~MoveHorizontalOnFixedUpdateCount() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		bool _bForward = true;
		int32_t _moveAmount = 0;
	};
}