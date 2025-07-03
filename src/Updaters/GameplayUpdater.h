#pragma once

#include "UpdaterBase.h"

namespace RB::Updaters
{
	class GameplayUpdater : public UpdaterBase
	{
	public:
		GameplayUpdater();
		~GameplayUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}
