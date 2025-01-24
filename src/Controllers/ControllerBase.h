#pragma once

#include <vector>

#include "ControllerType.h"
#include "iController.h"

#include "../olcPixelGameEngine.h"

namespace RB::Controllers
{
	iController* GetController(ControllerType controllerType);

	#define INIT_CONTROLLER if (!_initialized){ _initialized = true; } else { return; }

	class ControllerBase : public iController
	{
	public:
		static std::vector<ControllerBase*> vecControllers;

		template <typename T>
		static T* AddController(ControllerBase* controller)
		{
			controller->Init();

			vecControllers.push_back(controller);

			return (T*)controller;
		}

		static void UpdateAll();
		static void FixedUpdateAll();
		static void DestroyAllControllers();

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
		virtual bool IsInitialized() override;

	protected:
		ControllerType _controllerType = ControllerType::NONE;
		bool _initialized = false;
	};
}