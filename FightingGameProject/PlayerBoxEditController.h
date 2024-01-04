#pragma once

#include "iPlayerBoxEditController.h"

namespace RB::Collisions
{
	class PlayerBoxEditController : public RB::Collisions::iPlayerBoxEditController
	{
	public:
		PlayerBoxEditController() = default;
		~PlayerBoxEditController() override {}

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}