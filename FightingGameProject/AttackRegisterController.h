#pragma once
#include <vector>

#include "iAttackRegisterController.h"

namespace RB::Collisions
{
	class AttackRegisterController : public iAttackRegisterController
	{
	public:
		AttackRegisterController();
		~AttackRegisterController() override;

	public:
		void RegisterAttack(AttackRegister attackRegister) override;
		void ProcessHits() override;

	private:
		std::vector<AttackRegister> _vec_p1_hits_taken;
		std::vector<AttackRegister> _vec_p2_hits_taken;
	};
}