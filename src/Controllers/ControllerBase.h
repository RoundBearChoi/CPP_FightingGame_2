#pragma once

#include <vector>

#include "ControllerType.h"
#include "iController.h"

#include "../olcPixelGameEngine.h"

namespace RB::Controllers
{
	iController* GetController(ControllerType controllerType);

	class ControllerBase : public iController
	{
	public:
		ControllerBase() = default;
		virtual ~ControllerBase() override {};

	public:
		virtual void Init() override = 0;
		virtual void OnUpdate() override = 0;
		virtual void OnFixedUpdate() override = 0;

	public:
		virtual ControllerType GetControllerType() override;
		virtual void SetControllerType(ControllerType controllerType) override;
		//virtual bool IsInitialized() override;

	protected:
		ControllerType _controllerType = ControllerType::NONE;
		//bool _initialized = false;
	};
}
