#include "P0_JumpUp.h"

namespace RB::P0_States
{
	P0_JumpUp::P0_JumpUp()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_jump_up;
	}

	void P0_JumpUp::OnEnter()
	{
		RB::Players::PlayerController* pc = RB::Controllers::CurrentControllers::GetController<RB::Players::PlayerController>();
		_ownerPlayer = pc->GetPlayerOnStateMachineID(_stateMachine->GetID());

		float startUpMomentum = 9.0f;
		_ownerPlayer->SetAirMomentum(olc::vf2d{ 0.0f, startUpMomentum });
	}

	void P0_JumpUp::OnUpdate()
	{

	}

	void P0_JumpUp::OnFixedUpdate()
	{
		olc::vf2d momentum = _ownerPlayer->GetAirMomentum();

		if (momentum.y < 0.5f)
		{
			_ownerPlayer->SetAirMomentum(olc::vf2d{ momentum.x, 0.0f });

			_stateMachine->QueueNextState(new RB::P0_States::P0_FallDown());
		}
		else
		{
			float y = _ownerPlayer->GetAirMomentum().y;

			_ownerPlayer->Move(olc::vf2d{ 0.0f, -y });

			float ySlowAmount = 0.3f;

			_ownerPlayer->AddMomentum(olc::vf2d{ 0.0f, -ySlowAmount });
		}
	}
}