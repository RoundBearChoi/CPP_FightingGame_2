#pragma once
#include "iInputController.h"

namespace RB::Input
{
	class CurrentInputController
	{
	public:
		CurrentInputController() {}
		~CurrentInputController() {}

	public:
		static void Init()
		{
			_inputController = nullptr;
			_controllerExists = false;
		}

		//static void OnUpdate()
		//{
		//	if (_controllerExists)
		//	{
		//		_inputController->OnUpdate();
		//	}
		//}

		//static void OnFixedUpdate()
		//{
		//	if (_controllerExists)
		//	{
		//		_inputController->OnFixedUpdate();
		//	}
		//}

	public:
		static void SetCurrentInputController(iInputController* controller)
		{
			_inputController = controller;

			if (_inputController != nullptr)
			{
				_controllerExists = true;
			}
		}

		static bool ControllerExists()
		{
			return _controllerExists;
		}

		static iInputController* GetController()
		{
			return _inputController;
		}

	private:
		static inline iInputController* _inputController = nullptr;
		static inline bool _controllerExists = false;
	};
}