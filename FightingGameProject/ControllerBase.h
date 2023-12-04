#pragma once
#include <iostream>
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
		virtual ~ControllerBase() override {}

	public:
		virtual void SetHash(const type_info& ti);
		virtual size_t GetHash() override;

	public:
		virtual void Init() override {};
		virtual void OnUpdate() override {};
		virtual void OnFixedUpdate() override {};

	protected:
		size_t _hash = 0;
	};
}