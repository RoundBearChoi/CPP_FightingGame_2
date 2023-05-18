#pragma once
#include <iostream>
#include <vector>
#include "iController.h"

namespace RB::Controllers
{
	class ActiveControllers
	{
	public:
		static void OnEnd();
		static void AddController(iController* newController);
		/// <summary>
		/// very slow!
		/// only use this for initialization
		/// </summary>
		template<class T> static T* GetController();
		static void UpdateAll();
		static void FixedUpdateAll();

	private:
		static void _DestroyAll();

	private:
		inline static std::vector<iController*> _vecControllers;
	};

	template<class T>
	inline T* ActiveControllers::GetController()
	{
		std::string name = typeid(T).name();
		std::hash<std::string> hasher;
		size_t hash = hasher(name);

		for (size_t i = 0; i < _vecControllers.size(); i++)
		{
			if (_vecControllers[i]->GetHash() == hash)
			{
				return dynamic_cast<T*>(_vecControllers[i]);
			}
		}

		return nullptr;
	}
}