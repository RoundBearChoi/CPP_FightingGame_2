#include "P0_Hadouken.h"

namespace RB::PlayerStates
{
	void P0_Hadouken::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_hadouken);

		//AddStateComponent(new RB::PlayerStateComponents::TriggerJumpForward());
		//AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		//AddStateComponent(new RB::PlayerStateComponents::TriggerJab(new P0_Jab()));
		//AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		//AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Hadouken::OnExit()
	{
		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Hadouken::OnUpdate()
	{

	}

	void P0_Hadouken::OnFixedUpdate()
	{

	}
}