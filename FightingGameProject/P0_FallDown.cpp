#include "P0_FallDown.h"

namespace RB::PlayerStates
{
	void P0_FallDown::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_fall);

		olc::vf2d fallMomentum = olc::vf2d{ _ownerPlayer->GetAirMomentum().x , 6.0f };

		_ownerPlayer->SetAirMomentum(fallMomentum);
	}

	void P0_FallDown::OnExit()
	{
		ActivePlayerStates::RemovePlayerState(this);
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

			RB::States::iStateMachine* machine = _ownerPlayer->GetStateMachine();
			machine->QueueNextState(new RB::PlayerStates::P0_Idle());
		}
	}
}