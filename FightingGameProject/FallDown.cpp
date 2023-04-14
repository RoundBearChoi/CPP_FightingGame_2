#include "FallDown.h"

namespace RB::PlayerStates
{
	FallDown::FallDown()
	{

	}

	void FallDown::OnEnter()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		RB::Players::PlayerID id = owner->GetPlayerID();

		//std::cout << std::endl;
		//std::cout << "player " << static_cast<int>(id) << " fall down" << std::endl;

		olc::vf2d fallMomentum = olc::vf2d{ owner->GetAirMomentum().x , 6.0f };

		owner->SetAirMomentum(fallMomentum);
	}

	void FallDown::OnUpdate()
	{

	}

	void FallDown::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		olc::vf2d momentum = owner->GetAirMomentum();

		if (owner->GetPosition().y < -0.5f)
		{
			owner->Move(olc::vf2d{ 0.0f, momentum.y });
		}
		else
		{
			owner->SetPosition(olc::vi2d{ owner->GetPosition().x, 0 });
			owner->SetAirMomentum(olc::vf2d{ 0.0f, 0.0f });

			_stateMachine->QueueNextState(new RB::PlayerStates::Idle());
		}
	}
}