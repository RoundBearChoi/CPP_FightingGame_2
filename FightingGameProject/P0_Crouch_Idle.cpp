#include "P0_Crouch_Idle.h"

#include "FixDirectionDuringState.h"
#include "StandUpOnRelease.h"

#include "P0_StandUp.h"

namespace RB::PlayerStates::Aku
{
	void P0_Crouch_Idle::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_crouch_idle;

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::StandUpOnRelease(new RB::PlayerStates::Aku::P0_StandUp()));

		EnterStateComponents();
	}

	void P0_Crouch_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Crouch_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Crouch_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}