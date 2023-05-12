#include "P0_FallDown.h"

namespace RB::P0_States
{
	P0_FallDown::P0_FallDown()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_fall;
	}

	void P0_FallDown::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::ActiveControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_stateMachine->GetID());

		olc::vf2d fallMomentum = olc::vf2d{ _ownerPlayer->GetAirMomentum().x , 6.0f };

		_ownerPlayer->SetAirMomentum(fallMomentum);
	}

	void P0_FallDown::OnUpdate()
	{

	}

	void P0_FallDown::OnFixedUpdate()
	{
		olc::vf2d momentum = _ownerPlayer->GetAirMomentum();

		if (_ownerPlayer->GetPosition().y < -0.5f)
		{
			_ownerPlayer->Move(olc::vf2d{ 0.0f, momentum.y });
		}
		else
		{
			_ownerPlayer->SetPosition(olc::vi2d{ _ownerPlayer->GetPosition().x, 0 });
			_ownerPlayer->SetAirMomentum(olc::vf2d{ 0.0f, 0.0f });

			_stateMachine->QueueNextState(new RB::P0_States::P0_Idle());
		}
	}
}