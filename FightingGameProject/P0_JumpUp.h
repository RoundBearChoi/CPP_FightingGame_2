#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "P0_FallDown.h"

namespace RB::P0_States
{
	class P0_JumpUp : public RB::States::StateBase
	{
	public:
		P0_JumpUp();
		~P0_JumpUp() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}