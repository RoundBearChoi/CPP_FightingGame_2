#include "AttackRegisterController.h"

namespace RB::Collisions
{
	AttackRegisterController::AttackRegisterController()
	{
		SetHash(typeid(*this));

		ATTACK_REGISTER_CONTROLLER = this;
	}

	AttackRegisterController::~AttackRegisterController()
	{
		ATTACK_REGISTER_CONTROLLER = nullptr;
	}

	void AttackRegisterController::RegisterAttack(AttackRegister attackRegister)
	{
		if (RB::Players::PlayerID::PLAYER_1 == attackRegister.target->GetPlayerID())
		{
			_vec_p1_hits_taken.push_back(attackRegister);
		}
		else if (RB::Players::PlayerID::PLAYER_2 == attackRegister.target->GetPlayerID())
		{
			_vec_p2_hits_taken.push_back(attackRegister);
		}
	}

	void AttackRegisterController::ProcessHits()
	{

	}
}