#pragma once

#include <iostream>
#include <assert.h>

#include "../olcPixelGameEngine.h"

#include "../Updaters/Scheduler.h"

#include "GameplayUpdater.h"
#include "PlayerBoxEditorUpdater.h"
#include "AttackBoxEditorUpdater.h"
#include "TargetBoxEditorUpdater.h"

#include "Skipper.h"

#include "iPlayground.h"
#include "iUpdater.h"

#include "../Collisions/iHitStopController.h"

namespace RB::Updaters
{
	class Playground : public iPlayground
	{
	public:
		Playground();
		~Playground() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
		void SetFixedUpdateSkips(int skips) override;
		void ClearFixedUpdateSkip(int fixedUpdates) override;
		bool QueueAttackBoxEditorUpdater() override;
		bool QueueTargetBoxEditorUpdater() override;
		iUpdater* GetUpdater() override;

	public:
		void SetUpdater(iUpdater* updater);
		bool QueueUpdater(iUpdater* updater);
		void UpdateQueue();
		void MakeUpdaterTransition();

	private:
		void _RunCustomUpdate();
		void _ClearSkips();

	private:
		bool _updaterIsQueued = false;
		iUpdater* _updater = nullptr;
		iUpdater* _nextUpdater = nullptr;
		Skipper _skipper;
		Scheduler _scheduler;
	};
}
