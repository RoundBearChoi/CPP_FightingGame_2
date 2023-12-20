#pragma once

#include "iSpecsController.h"

namespace RB::Players::Specs
{
	class SpecsController : public iSpecsController
	{
	public:
		SpecsController() = default;
		~SpecsController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}