#pragma once

#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class Updater
	{
	public:
		Updater();
		~Updater();

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