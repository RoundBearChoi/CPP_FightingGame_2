#pragma once
#include <iostream>
#include "iUpdaterObj.h"

namespace RB::Engine
{
	class Updaters
	{
	private:
		iUpdaterObj* _updaterObj = nullptr;

	public:
		Updaters();
		~Updaters();

		void Init();
		void OnUpdate();
	};
}