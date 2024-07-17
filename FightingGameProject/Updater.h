#pragma once

#include <iostream>
#include <assert.h>

#include "olcPixelGameEngine.h"

#include "GameplayUpdater.h"
#include "PlayerBoxEditorUpdater.h"
#include "AttackBoxEditorUpdater.h"
#include "TargetBoxEditorUpdater.h"

#include "iUpdater.h"
#include "iUpdaterObj.h"
#include "iGeneralHitStopController.h"

namespace RB::Updaters
{
	class Updater : public iUpdater
	{
	public:
		Updater();
		~Updater();

	public:
		bool QueueAttackBoxEditorUpdater() override;
		bool QueueTargetBoxEditorUpdater() override;

	public:
		void SetUpdaterObj(iUpdaterObj* updaterObj);
		bool QueueUpdaterObj(iUpdaterObj* updaterObj);
		void UpdateQueue();
		void MakeUpdaterTransition();

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		bool _updaterIsQueued = false;
		iUpdaterObj* _updaterObj = nullptr;
		iUpdaterObj* _nextUpdaterObj = nullptr;
	};
}
