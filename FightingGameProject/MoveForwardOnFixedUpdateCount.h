#pragma once
#include <cstdint>
#include "StateComponentBase.h"

#include "iPlayer.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveForwardOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		MoveForwardOnFixedUpdateCount(int32_t fixedUpdateOnCount);
		~MoveForwardOnFixedUpdateCount() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}