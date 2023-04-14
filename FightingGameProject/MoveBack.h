#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"
#include "Idle.h"
#include "MoveForward.h"

namespace RB::PlayerStates
{
	class MoveBack : public RB::States::StateBase
	{
	public:
		MoveBack();

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}