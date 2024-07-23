#include "P0_Dummy.h"

namespace RB::Fighter_0_States
{
	P0_Dummy::P0_Dummy(Sprites::SpriteType startingSpriteType)
	{
		_spriteType = startingSpriteType;
	}

	void P0_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteType);
	}

	void P0_Dummy::OnExit()
	{

	}

	void P0_Dummy::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}
