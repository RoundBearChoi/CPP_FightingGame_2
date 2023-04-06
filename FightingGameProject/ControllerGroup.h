#pragma once
#include <iostream>
#include <vector>
#include "iController.h"

using namespace std;

namespace RB::Controllers
{
	class ControllerGroup
	{
	private:
		static vector<iController> _vecControllers;
		static vector<int> _test;

	public:
		static void Init();
		static void OnEnd();

	};
}