#include "P0_Idle_Dummy.h"

namespace RB::P0_States
{
	P0_Idle_Dummy::P0_Idle_Dummy()
	{
		_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
	}

	void P0_Idle_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteID);
		_manualTransitioner.OnEnter(_stateMachineID, new P0_FallDown_Dummy(), nullptr);
	}

	void P0_Idle_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
		_manualTransitioner.OnUpdate();
	}

	void P0_Idle_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
		_manualTransitioner.OnFixedUpdate();
	}
}