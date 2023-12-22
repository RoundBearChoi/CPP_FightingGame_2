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

	public:
		void RegisterAttack(AttackRegister attackRegister) override;
		//void ProcessHits() override;
		size_t GetRegisteredAttackCount(RB::Players::PlayerID playerID) override;

	private:
		std::vector<AttackRegister> _vec_p1_hits_taken;
		std::vector<AttackRegister> _vec_p2_hits_taken;
	};
}