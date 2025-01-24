#include "ControllerBase.h"

#include "../Updaters/CurrentPlayground.h"
#include "../Updaters/iUpdater.h"
#include "iController.h"

namespace RB::Controllers
{
	std::vector<ControllerBase*> ControllerBase::vecControllers;

	iController* GetController(ControllerType controllerType)
	{
		if (RB::Updaters::ptrCurrentPlayground != nullptr)
		{
			Updaters::iUpdater* updater = Updaters::ptrCurrentPlayground->GetUpdater();

			iController* controller =  updater->GetController(controllerType);

			return controller;
		}

		return nullptr;
	}

	void ControllerBase::UpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnUpdate();
		}
	}

	void ControllerBase::FixedUpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void ControllerBase::DestroyAllControllers()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vecControllers.clear();
	}

	ControllerType ControllerBase::GetControllerType()
	{
		return _controllerType;
	}

	void ControllerBase::SetControllerType(ControllerType controllerType)
	{
		_controllerType = controllerType;
	}
}