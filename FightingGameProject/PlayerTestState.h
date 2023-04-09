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
		~PlayerTestState() override;

		void OnFixedUpdate() override;

	private:
		//RB::Updaters::SkipFrameUpdater _updater;
		//void _SomeFunc();
	};
}