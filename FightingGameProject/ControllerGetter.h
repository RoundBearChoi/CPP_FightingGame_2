#pragma once
#include "ActiveControllers.h"

namespace RB::Controllers
{
	template <class T>
	class ControllerGetter
	{
	public:
		ControllerGetter() = default;
		~ControllerGetter() = default;

	public:
		void OnUpdate()
		{
			FindController();
		}

		T* GetController();
		void FindController();

	private:
		T* _controller = nullptr;
		bool _controllerFound = false;
		int32_t _searchCount = 0;
	};

	template<class T>
	void ControllerGetter<T>::FindController()
	{
		if (_searchCount >= 5)
		{
			return;
		}

		if (_controllerFound)
		{
			return;
		}

		_controller = RB::Controllers::ActiveControllers::GetController<T>();
		_searchCount++;

		if (_controller != nullptr)
		{
			_controllerFound = true;
		}
	}

	template<class T>
	T* ControllerGetter<T>::GetController()
	{
		return _controller;
	}
}