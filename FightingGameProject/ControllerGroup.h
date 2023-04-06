#pragma once
#include <iostream>
#include <vector>
#include "iController.h"

using namespace std;

namespace RB::Controllers
{
	class ControllerGroup
	{
	public:
		static void Init();
		static void OnEnd();

	private:
		static vector<iController> _vecControllers;
		static vector<int> _test;

		static void _DestroyAll();
	};
}