#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerState.h"
#include "ActivePlayerStates.h"

#include "DetectHit.h"
#include "TriggerIdleOnAnimationEnd.h"

namespace RB::PlayerStates
{
	class P0_Jab : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Jab() = default;

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}