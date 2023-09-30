#pragma once
#include "ControllerBase.h"

#include "AttackRegister.h"

namespace RB::Collisions
{
	class iAttackRegisterController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual void RegisterAttack(AttackRegister attackRegister) = 0;
		virtual void ProcessHits() = 0;
	};

	extern iAttackRegisterController* ATTACK_REGISTER_CONTROLLER;
}