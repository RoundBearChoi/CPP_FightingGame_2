#pragma once
#include <iostream>
#include "StateBase.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "P0_Idle.h"

namespace RB::P0_States
{
	class P0_FallDown : public RB::States::StateBase
	{
	public:
		P0_FallDown();

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}