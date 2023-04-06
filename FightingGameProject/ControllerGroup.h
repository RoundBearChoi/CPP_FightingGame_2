#pragma once
#include <iostream>
#include <vector>
#include "ControllerBase.h"

using namespace std;

namespace RB::Controllers
{
	class ControllerGroup
	{
	public:
		static void Init();
		static void OnEnd();
		static void AddController(ControllerBase* newController);
		static void UpdateAll();
		static void FixedUpdateAll();

	private:
		static vector<ControllerBase*> _vecControllers;

		static void _DestroyAll();
	};
}