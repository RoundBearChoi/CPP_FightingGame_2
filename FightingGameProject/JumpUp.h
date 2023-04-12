#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "iPlayer.h"
#include "PlayerID.h"

namespace RB::PlayerStates
{
	class JumpUp : public RB::States::StateBase
	{
	public:
		JumpUp();
		~JumpUp() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}