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
		static void AddController(iController* newController);
		static void UpdateAll();
		static void FixedUpdateAll();
		template <typename T> static T* FindController();
	private:
		static vector<iController*> _vecControllers;

		static void _DestroyAll();
	};

	template<typename T> inline T* ControllerGroup::FindController()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			bool t1 = is_same<int, int>::value;
			bool t2 = is_assignable<int, double>::value;
			bool t3 = is_convertible<int, float>::value;

			int j = 0;

			int ff = 0;

			string nn = typeid(_vecControllers).name();
		}

		return nullptr;
	}
}