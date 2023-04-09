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
		template <class T> static T* FindController();
	private:
		inline static vector<iController*> _vecControllers;

		static void _DestroyAll();
	};

	template<class T> inline T* ControllerGroup::FindController()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			T* d = dynamic_cast<T*>(_vecControllers[i]);

			if (d != nullptr)
			{
				return d;
			}
		}

		return nullptr;
	}
}