#include "P0_Idle_Dummy.h"

namespace RB::P0_States
{
	P0_Idle_Dummy::P0_Idle_Dummy()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;
	}

	void P0_Idle_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteEnum);
		//_manualTransitioner.OnEnter(_stateMachineID, new P0_FallDown_Dummy(), new P0_JumpUp_Dummy);
	}

	void P0_Idle_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
		//_manualTransitioner.OnUpdate();
	}

	void P0_Idle_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
		//_manualTransitioner.OnFixedUpdate();
	}
}