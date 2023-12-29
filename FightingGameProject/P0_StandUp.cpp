#include "P0_StandUp.h"

#include "FixDirectionDuringState.h"

namespace RB::PlayerStates::Aku
{
	void P0_StandUp::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_standup;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(true));
		//AddStateComponent(new RB::PlayerStateComponents::StandUpOnRelease(new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_StandUp::OnExit()
	{
		ExitStateComponents();

	}

	void P0_StandUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_StandUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}