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
		return nullptr;
	}
}