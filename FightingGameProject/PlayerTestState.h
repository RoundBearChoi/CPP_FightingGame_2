#pragma once
#include <iostream>
#include "StateBase.h"
#include "GameplayControllers.h"
#include "iPlayer.h"
#include "SkipFrameUpdater.h"

namespace RB::PlayerStates
{
	class PlayerTestState : public RB::States::StateBase
	{
	public:
		PlayerTestState();
		~PlayerTestState() override;

	public:
		void OnEnter() override;
		void OnFixedUpdate() override;

	public:
		void Move();

	private:
		Updaters::SkipFrameUpdater<PlayerTestState> _skipFrame;
	};
}