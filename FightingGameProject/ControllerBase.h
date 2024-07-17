#pragma once

#include <vector>

#include "olcPixelGameEngine.h"

namespace RB::Controllers
{
	class ControllerBase
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
		virtual ~ControllerBase() {};

	public:
		virtual void Init() {};
		virtual void OnUpdate() {};
		virtual void OnFixedUpdate() {};
	};
}
