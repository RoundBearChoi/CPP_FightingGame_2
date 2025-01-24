#pragma once

#include "AttackRegister.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Collisions
{
	#define GET_ATTACK_REGISTER_CONTROLLER static_cast<RB::Collisions::iAttackRegisterController*>(RB::Controllers::GetController(Controllers::ControllerType::ATTACK_REGISTER_CONTROLLER))
	
	class iAttackRegisterController : public Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual bool RegisterAttack(AttackRegister reg) = 0;
	};
}