#include "P0_JumpUp.h"

namespace RB::P0_States
{
	P0_JumpUp::P0_JumpUp()
	{

	}

	void P0_JumpUp::OnEnter()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		RB::Players::PlayerID id = owner->GetPlayerID();

		float startUpMomentum = 9.0f;

		owner->SetAirMomentum(olc::vf2d{ 0.0f, startUpMomentum });
	}

	void P0_JumpUp::OnUpdate()
	{

	}

	void P0_JumpUp::OnFixedUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		olc::vf2d momentum = owner->GetAirMomentum();

		if (momentum.y < 0.5f)
		{
			owner->SetAirMomentum(olc::vf2d{ momentum.x, 0.0f });

			_stateMachine->QueueNextState(new RB::P0_States::P0_FallDown());
		}
		else
		{
			float y = owner->GetAirMomentum().y;

			owner->Move(olc::vf2d{ 0.0f, -y });

			float ySlowAmount = 0.3f;

			owner->AddMomentum(olc::vf2d{ 0.0f, -ySlowAmount });
		}
	}
}