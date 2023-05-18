#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "PlayerID.h"
#include "iPlayer.h"

#include "P0_FallDown.h"

namespace RB::P0_States
{
	class P0_JumpUp : public RB::States::StateBase
	{
	public:
		P0_JumpUp() = default;
		~P0_JumpUp() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
	};
}