#pragma once
#include "ControllerT.h"

#include "AttackRegister.h"

namespace RB::Collisions
{
	class iAttackRegisterController : public RB::Controllers::ControllerT<iAttackRegisterController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual void RegisterAttack(AttackRegister reg) = 0;
	};
}