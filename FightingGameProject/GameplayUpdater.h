#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class GameplayUpdater : public iUpdaterObj
	{
	public:
		GameplayUpdater() = default;
		~GameplayUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}