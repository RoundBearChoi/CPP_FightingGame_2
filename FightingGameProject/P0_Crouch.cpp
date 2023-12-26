#include "P0_Crouch.h"

namespace RB::PlayerStates::Aku
{
	void P0_Crouch::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_crouch;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::StandUpOnRelease(new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Crouch::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Crouch::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Crouch::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}