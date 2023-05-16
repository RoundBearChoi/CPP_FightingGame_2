#include "P0_FallDown_Dummy.h"

namespace RB::P0_States
{
	P0_FallDown_Dummy::P0_FallDown_Dummy()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_fall;
	}

	void P0_FallDown_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteEnum);
		//_manualTransitioner.OnEnter(_stateMachineID, new P0_JumpUp_Dummy, new P0_Idle_Dummy());
	}

	void P0_FallDown_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
		//_manualTransitioner.OnUpdate();
	}

	void P0_FallDown_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
		//_manualTransitioner.OnFixedUpdate();
	}
}