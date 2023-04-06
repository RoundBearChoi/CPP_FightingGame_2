#pragma once
#include <iostream>
#include <vector>

using namespace std;

namespace RB::Controllers
{
	class ControllerGroup
	{
	public:
		static void Init();
		static void OnEnd();

		static vector<int> _test;
	};
}