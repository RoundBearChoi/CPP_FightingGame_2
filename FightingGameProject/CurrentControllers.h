#pragma once
#include <iostream>
#include <vector>
#include "iController.h"

namespace RB::Controllers
{
	class CurrentControllers
	{
	public:
		static void Init();
		static void OnEnd();
		static void AddController(iController* newController);
		/// <summary>
		/// very slow!
		/// only use this for initialization
		/// </summary>
		static iController* GetController(const std::type_info& ti);
		static void UpdateAll();
		static void FixedUpdateAll();
		template <class T> static T* FindController();

	private:
		inline static std::vector<iController*> _vecControllers;

		static void _DestroyAll();
	};

	template<class T> T* CurrentControllers::FindController()
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