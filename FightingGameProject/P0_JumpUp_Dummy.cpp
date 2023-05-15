#include "P0_JumpUp_Dummy.h"

namespace RB::P0_States
{
	P0_JumpUp_Dummy::P0_JumpUp_Dummy()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_jump_up;
	}

	void P0_JumpUp_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteID);
		_manualTransitioner.OnEnter(_stateMachineID, new P0_Idle_Dummy, new P0_FallDown_Dummy());
	}

	void P0_JumpUp_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
		_manualTransitioner.OnUpdate();
	}

	void P0_JumpUp_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
		_manualTransitioner.OnFixedUpdate();
	}

}