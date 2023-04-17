#pragma once
#include <iostream>
#include "StateBase.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "Idle.h"

namespace RB::Player0_States
{
	class FallDown : public RB::States::StateBase
	{
	public:
		FallDown();

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}