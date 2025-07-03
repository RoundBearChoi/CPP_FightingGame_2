#pragma once

#include "UpdaterType.h"

#include "../Controllers/iController.h"
#include "../Controllers/ControllerType.h"

namespace RB::Updaters
{
	class iUpdater
	{
	public:
		iUpdater() = default;
		virtual ~iUpdater() = default;

		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual Controllers::iController* AddController(Controllers::iController* controller, Controllers::ControllerType controllerType) = 0;
		virtual Controllers::iController* GetController(Controllers::ControllerType controllerType) = 0;
		virtual UPDATER_TYPE GetUpdaterType() = 0;
	};
}
