#include "P0_Jab.h"

namespace RB::PlayerStates
{
	void P0_Jab::OnEnter()
	{
		StandardInit(RB::Sprites::SpriteEnum::fighter_0_jab);

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(_ownerPlayer->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::DetectHit());
		AddStateComponent(new RB::PlayerStateComponents::TriggerIdleOnAnimationEnd());

		EnterStateComponents();
	}

	void P0_Jab::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Jab::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Jab::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}