#pragma once

#include "iAttackSpecsController.h"

namespace RB::Collisions
{
	class AttackSpecsController : public iAttackSpecsController
	{
	public:
		AttackSpecsController() = default;
		~AttackSpecsController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}