#include "JumpUp.h"

namespace RB::PlayerStates
{
	JumpUp::JumpUp()
	{

	}

	JumpUp::~JumpUp()
	{

	}

	void JumpUp::OnEnter()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		RB::Players::PlayerID id = owner->GetPlayerID();

		std::cout << std::endl;
		std::cout << "player " << static_cast<int>(id) << " jump up" << std::endl;

		owner->SetAirMomentum(olc::vf2d{ 0.0f, 5.0f });
	}

	void JumpUp::OnUpdate()
	{

	}

	void JumpUp::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		olc::vf2d momentum = owner->GetAirMomentum();

		if (momentum.y < 0.5f)
		{
			owner->SetAirMomentum(olc::vf2d{ momentum.x, 0.0f });
		}
		else
		{
			std::cout << "player " << static_cast<int>(owner->GetPlayerID()) << " y momentum: " << momentum.y << std::endl;

			owner->AddMomentum(olc::vf2d{ 0.0f, -0.1f });
		}
	}
}