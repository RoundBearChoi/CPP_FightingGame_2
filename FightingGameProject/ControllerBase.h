#pragma once
#include <vector>
#include "iController.h"

namespace RB::Controllers
{
	class ControllerBase : public iController
	{
	public:
		static std::vector<iController*> vecControllers;
		static void AddController(iController* controller);
		static void UpdateAll();
		static void FixedUpdateAll();
		static void OnEnd();

	public:
		ControllerBase() = default;
		virtual ~ControllerBase() override;

	public:
		virtual void Init() override {};
		virtual void OnUpdate() override {};
		virtual void OnFixedUpdate() override {};
	};
}