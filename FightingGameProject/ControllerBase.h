#pragma once
#include "iController.h"

namespace RB::Controllers
{
	class ControllerBase : public iController
	{
	public:
		ControllerBase() = default;
		virtual ~ControllerBase() override {}

	public:
		size_t GetHash() override;

	public:
		virtual void Init() override {};
		virtual void OnUpdate() override {};
		virtual void OnFixedUpdate() override {};
	};
}