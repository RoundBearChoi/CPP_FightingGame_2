#include "P0_Crouch.h"

namespace RB::PlayerStates::Aku
{
	void P0_Crouch::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_crouch;

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));

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