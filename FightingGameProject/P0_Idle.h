#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerState.h"

#include "FixDirectionDuringState.h"
#include "TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "TransitionOnInput.h"
#include "TransitionToWalkForward.h"
#include "TransitionToWalkBack.h"

#include "P0_Crouch.h"

namespace RB::PlayerStates::Aku
{
	class P0_Idle : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Idle() = default;
		~P0_Idle()
		{
			std::cout << "deleting state: P0_Idle" << std::endl;
		}

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}