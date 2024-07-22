#pragma once

#include <iostream>
#include <assert.h>

#include "olcPixelGameEngine.h"

#include "Updaters/GameplayUpdater.h"
#include "PlayerBoxEditorUpdater.h"
#include "Updaters/AttackBoxEditorUpdater.h"
#include "TargetBoxEditorUpdater.h"

#include "iUpdater.h"
#include "iUpdaterObj.h"
#include "Collisions/iGeneralHitStopController.h"

namespace RB::Updaters
{
	class Updater : public iUpdater
	{
	public:
		Updater();
		~Updater() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		bool QueueAttackBoxEditorUpdater() override;
		bool QueueTargetBoxEditorUpdater() override;

	public:
		void SetUpdaterObj(iUpdaterObj* updaterObj);
		bool QueueUpdaterObj(iUpdaterObj* updaterObj);
		void UpdateQueue();
		void MakeUpdaterTransition();

	private:
		bool _updaterIsQueued = false;
		iUpdaterObj* _updaterObj = nullptr;
		iUpdaterObj* _nextUpdaterObj = nullptr;
	};
}
