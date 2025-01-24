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
		virtual void Init() override {};
		virtual void OnUpdate() override {};
		virtual void OnFixedUpdate() override {};
		virtual ControllerType GetControllerType() override;
		virtual void SetControllerType(ControllerType controllerType) override;

	protected:
		ControllerType _controllerType = ControllerType::NONE;
	};
}