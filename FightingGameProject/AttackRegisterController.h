#pragma once
#include <vector>

#include "iAttackRegisterController.h"

namespace RB::Collisions
{
	class AttackRegisterController : public iAttackRegisterController
	{
	public:
		AttackRegisterController() = default;
		~AttackRegisterController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}