#pragma once
#include <iostream>
#include "iController.h"

namespace RB::Controllers
{
	class ControllerBase : public iController
	{
	public:
		ControllerBase() = default;
		virtual ~ControllerBase() override {}

	public:
		virtual void SetHash(std::string str);
		virtual size_t GetHash() override;

	public:
		virtual void Init() override {};
		virtual void OnUpdate() override {};
		virtual void OnFixedUpdate() override {};

	protected:
		size_t _hash = 0;
	};
}