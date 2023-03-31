#pragma once
#include <iostream>
#include "iUpdater.h"

namespace RB::Engine
{
	class Updaters
	{
	private:
		iUpdater* _updaterObj = nullptr;

	public:
		Updaters();
		~Updaters();

		void Init();
		void OnUpdate();
	};
}