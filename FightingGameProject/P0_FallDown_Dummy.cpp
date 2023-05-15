#include "P0_FallDown_Dummy.h"

namespace RB::P0_States
{
	P0_FallDown_Dummy::P0_FallDown_Dummy()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_fall;
	}

	void P0_FallDown_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteID);
		_manualTransitioner.OnEnter(_stateMachineID, nullptr, new P0_Idle_Dummy());
	}

	void P0_FallDown_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
		_manualTransitioner.OnUpdate();
	}

	void P0_FallDown_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
		_manualTransitioner.OnFixedUpdate();
	}
}