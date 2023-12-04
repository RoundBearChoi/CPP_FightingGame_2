#include "P0_FallDown.h"

namespace RB::PlayerStates
{
	void P0_FallDown::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_fall;

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 20.0f, new P0_Idle()));

		EnterStateComponents();
	}

	void P0_FallDown::OnExit()
	{
		ExitStateComponents();
	}

	void P0_FallDown::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_FallDown::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}