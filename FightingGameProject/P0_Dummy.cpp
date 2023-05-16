#include "P0_Dummy.h"

namespace RB::P0_States
{
	P0_Dummy::P0_Dummy()
	{
		//change spriteEnum to edit different sprites
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;
		//_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_up;
	}

	void P0_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnUpdate()
	{
		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}