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

		//std::cout << std::endl;
		//std::cout << "player " << static_cast<int>(id) << " jump up" << std::endl;

		float startUpMomentum = 9.0f;

		owner->SetAirMomentum(olc::vf2d{ 0.0f, startUpMomentum });
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

			_stateMachine->QueueNextState(new RB::PlayerStates::FallDown());
		}
		else
		{
			float y = owner->GetAirMomentum().y;

			owner->Move(olc::vf2d{ 0.0f, -y });

			//std::cout << "player " << static_cast<int>(owner->GetPlayerID()) << " y momentum: " << momentum.y << std::endl;

			float ySlowAmount = 0.3f;

			owner->AddMomentum(olc::vf2d{ 0.0f, -ySlowAmount });
		}
	}
}