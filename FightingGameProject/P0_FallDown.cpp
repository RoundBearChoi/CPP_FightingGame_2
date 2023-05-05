#include "P0_FallDown.h"

namespace RB::P0_States
{
	P0_FallDown::P0_FallDown()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_fall;
	}

	void P0_FallDown::OnEnter()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();
		RB::Players::PlayerID id = owner->GetPlayerID();

		olc::vf2d fallMomentum = olc::vf2d{ owner->GetAirMomentum().x , 6.0f };

		owner->SetAirMomentum(fallMomentum);
	}

	void P0_FallDown::OnUpdate()
	{

	}

	void P0_FallDown::OnFixedUpdate()
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

			_stateMachine->QueueNextState(new RB::P0_States::P0_Idle());
		}
	}
}