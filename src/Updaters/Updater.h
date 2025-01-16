#pragma once

#include <iostream>
#include <assert.h>

#include "../olcPixelGameEngine.h"

#include "GameplayUpdater.h"
#include "PlayerBoxEditorUpdater.h"
#include "AttackBoxEditorUpdater.h"
#include "TargetBoxEditorUpdater.h"
#include "SkipFixedUpdates.h"

#include "iPlayground.h"
#include "iUpdaterObj.h"

#include "../Collisions/iGeneralHitStopController.h"

namespace RB::Updaters
{
	class Updater : public iPlayground
	{
	public:
		Updater();
		~Updater() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
		void SetFixedUpdateSkips(int skips) override;

		bool QueueAttackBoxEditorUpdater() override;
		bool QueueTargetBoxEditorUpdater() override;

	public:
		void SetUpdaterObj(iUpdaterObj* updaterObj);
		bool QueueUpdaterObj(iUpdaterObj* updaterObj);
		void UpdateQueue();
		void MakeUpdaterTransition();

	private:
		void _RunCustomUpdate();

	private:
		bool _updaterIsQueued = false;
		iUpdaterObj* _updaterObj = nullptr;
		iUpdaterObj* _nextUpdaterObj = nullptr;
		SkipFixedUpdates<Updater> _customUpdate;
	};
}