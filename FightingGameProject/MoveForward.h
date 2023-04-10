#pragma once
#include "StateBase.h"
#include "iPlayer.h"
#include "GameplayControllers.h"

namespace RB::PlayerStates
{
	class MoveForward : public RB::States::StateBase
	{
	public:
		MoveForward();
		~MoveForward() override;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}