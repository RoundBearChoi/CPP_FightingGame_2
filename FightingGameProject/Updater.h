#pragma once
#include <iostream>

namespace RB::Engine
{
	class UpdaterBase
	{
	public:
		UpdaterBase();
		~UpdaterBase();

		virtual void OnUpdate();
	};
}