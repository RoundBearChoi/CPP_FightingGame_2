#pragma once

#include <vector>

#include "iController.h"

#include "../olcPixelGameEngine.h"

namespace RB::Controllers
{
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
		ControllerType GetControllerType() override;

	protected:
		ControllerType _controllerType = ControllerType::NONE;
	};
}