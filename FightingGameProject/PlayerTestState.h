#pragma once
#include <iostream>
#include "StateBase.h"
#include "GameplayControllers.h"
#include "iPlayer.h"
#include "SkipFrameUpdater.h"

namespace RB::Players
{
	class PlayerTestState : public RB::States::StateBase
	{
	public:
		PlayerTestState();
		~PlayerTestState() override;

		void OnEnter() override;
		void OnFixedUpdate() override;

		void SomeFunc();

	private:

	};
}