#pragma once
#include <iostream>
#include "StateBase.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "Idle.h"

namespace RB::PlayerStates
{
	class FallDown : public RB::States::StateBase
	{
	public:
		FallDown();
		~FallDown() override;
	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}