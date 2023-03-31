#pragma once
#include <iostream>

namespace RB::Engine
{
	class Updater
	{
	public:
		Updater();
		~Updater();

		void OnUpdate();
	};
}