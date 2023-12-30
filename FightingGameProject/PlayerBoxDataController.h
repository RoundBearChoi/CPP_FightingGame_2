#pragma once

#include "iPlayerBoxDataController.h"

namespace RB::Collisions
{
	class PlayerBoxDataController : public iPlayerBoxDataController
	{
	public:
			PlayerBoxDataController() = default;
			~PlayerBoxDataController() override {}

	public:
			void Init() override;
			void OnUpdate() override;
			void OnFixedUpdate() override;
	};
}