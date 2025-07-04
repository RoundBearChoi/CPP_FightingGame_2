#include "F0_Dummy.h"

namespace RB::Fighter_0_States
{
	F0_Dummy::F0_Dummy(Sprites::SPRITE_TYPE startingSpriteType)
	{
		_spriteType = startingSpriteType;
	}

	void F0_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteType);
	}

	void F0_Dummy::OnExit()
	{

	}

	void F0_Dummy::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		_manualAnimationUpdater.OnUpdate();
	}

	void F0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}
