#include "P0_JumpUp.h"

namespace RB::PlayerStates
{
	void P0_JumpUp::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_jump_up);

		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(15, 28.0f, new P0_FallDown()));
		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(_ownerPlayer->OtherPlayerIsOnRightSide()));

		EnterStateComponents();
	}

	void P0_JumpUp::OnExit()
	{
		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_JumpUp::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}