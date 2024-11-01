#include "F0_Crouch_Punch_Weak.h"

namespace RB::Fighter_0_States
{
	void F0_Crouch_Punch_Weak::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_crouch_punch_weak;

        AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		//AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());

		EnterStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Crouch_Punch_Weak::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
