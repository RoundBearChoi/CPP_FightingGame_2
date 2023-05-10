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
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		iUpdaterObj* _updaterObj = nullptr;
	};
}