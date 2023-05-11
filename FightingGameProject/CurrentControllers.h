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
		template<class T> static T* GetController();
		static void UpdateAll();
		static void FixedUpdateAll();
		template <class T> static T* FindController();

	private:
		inline static std::vector<iController*> _vecControllers;

		static void _DestroyAll();
	};

	template<class T>
	inline T* CurrentControllers::GetController()
	{
		std::string name = typeid(T).name();
		std::hash<std::string> hasher;
		size_t hash = hasher(name);

		for (int i = 0; i < _vecControllers.size(); i++)
		{
			if (_vecControllers[i]->GetHash() == hash)
			{
				return dynamic_cast<T*>(_vecControllers[i]);
			}
		}

		return nullptr;
	}

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