#include "ControllerBase.h"

#include "../Updaters/CurrentPlayground.h"
#include "../Updaters/iUpdater.h"
#include "iController.h"

namespace RB::Controllers
{
	iController* GetController(ControllerType controllerType)
	{
		if (Updaters::ptrCurrentPlayground != nullptr)
		{
			Updaters::iUpdater* updater = Updaters::ptrCurrentPlayground->GetUpdater();

			iController* controller =  updater->GetController(controllerType);

			return controller;
		}

		return nullptr;
	}

	ControllerType ControllerBase::GetControllerType()
	{
		return _controllerType;
	}

	void ControllerBase::SetControllerType(ControllerType controllerType)
	{
		_controllerType = controllerType;
	}

	bool ControllerBase::IsInitialized()
	{
		return _initialized;
	}
}