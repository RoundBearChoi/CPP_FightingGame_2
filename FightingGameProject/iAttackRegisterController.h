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

	public:
		//virtual void RegisterAttack(AttackRegister attackRegister) = 0;
		//virtual void ProcessHits() = 0;
		//virtual size_t GetRegisteredAttackCount(RB::Players::PlayerID playerID) = 0;
	};
}