#include "P0_Dummy.h"

#include "iPlayerController.h"

namespace RB::PlayerStates::Aku
{
	P0_Dummy::P0_Dummy(Sprites::SpriteEnum startingSpriteEnum)
	{
		_spriteEnum = startingSpriteEnum;
	}

	void P0_Dummy::OnEnter()
	{
		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnExit()
	{

	}

	void P0_Dummy::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
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