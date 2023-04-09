#pragma once
#include <iostream>
#include "iUpdaterObj.h"
#include "TestUpdater.h"

namespace RB::Updaters
{
	class Updater
	{
	private:
		iUpdaterObj* _updaterObj = nullptr;

	public:
		Updater();
		~Updater();

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}