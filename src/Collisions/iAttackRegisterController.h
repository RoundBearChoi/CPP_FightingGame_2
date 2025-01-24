#pragma once

#include "AttackRegister.h"

#include "../Controllers/ControllerT.h"

namespace RB::Collisions
{
	class iAttackRegisterController : public Controllers::ControllerT<iAttackRegisterController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual bool RegisterAttack(AttackRegister reg) = 0;
	};
}