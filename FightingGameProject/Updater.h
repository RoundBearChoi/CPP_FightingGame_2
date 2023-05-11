#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "GameplayUpdater.h"

namespace RB::Updaters
{
	class Updater
	{
	public:
		Updater();
		~Updater();

	public:
		void SetUpdaterObj(iUpdaterObj* updaterObj);
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		bool _updaterObjExists = false;
		iUpdaterObj* _updaterObj = nullptr;
	};
}