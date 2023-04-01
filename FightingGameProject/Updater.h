#pragma once
#include <iostream>
#include "iUpdaterObj.h"

namespace RB::Engine
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