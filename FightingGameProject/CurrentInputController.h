#pragma once
#include "iInputController.h"

namespace RB::Input
{
	class CurrentInputController
	{
	public:
		CurrentInputController() = delete;
		~CurrentInputController() = delete;

	public:
		static void Init()
		{

		}

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