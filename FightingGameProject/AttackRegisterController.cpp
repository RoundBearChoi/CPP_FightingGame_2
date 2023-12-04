#include "AttackRegisterController.h"

namespace RB::Collisions
{
	AttackRegisterController::AttackRegisterController()
	{
		ATTACK_REGISTER_CONTROLLER = this;
	}

	AttackRegisterController::~AttackRegisterController()
	{
		ATTACK_REGISTER_CONTROLLER = nullptr;
	}

	void AttackRegisterController::Init()
	{

	}

	void AttackRegisterController::OnUpdate()
	{

	}

	void AttackRegisterController::OnFixedUpdate()
	{

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

	size_t AttackRegisterController::GetRegisteredAttackCount(RB::Players::PlayerID playerID)
	{
		if (playerID == RB::Players::PlayerID::PLAYER_1)
		{
			return _vec_p1_hits_taken.size();
		}
		else if (playerID == RB::Players::PlayerID::PLAYER_2)
		{
			return _vec_p2_hits_taken.size();
		}

		return 0;
	}
}