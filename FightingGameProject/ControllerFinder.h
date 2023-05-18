#pragma once
#include "ActiveControllers.h"

namespace RB::Controllers
{
	template <class T>
	class ControllerFinder
	{
	public:
		ControllerFinder() = default;
		~ControllerFinder() = default;

	public:
		void Init()
		{

		}

		void OnUpdate()
		{
			_controller = FindController();
		}

		T* GetController();
		T* FindController();

	private:
		T* _controller = nullptr;
		bool _controllerFound = false;
		int32_t _searchCount = 0;
	};

	template<class T>
	T* ControllerFinder<T>::FindController()
	{
		if (_searchCount >= 5)
		{
			return nullptr;
		}

		if (_controllerFound)
		{
			return _controller;
		}

		_controller = RB::Controllers::ActiveControllers::GetController<T>();
		_searchCount++;
		return _controller;
	}

	template<class T>
	T* ControllerFinder<T>::GetController()
	{
		return _controller;
	}
}