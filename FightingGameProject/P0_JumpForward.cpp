#include "P0_JumpForward.h"

namespace RB::PlayerStates
{
	void P0_JumpForward::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_jump_forward);

		//AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(15, 25.0f));

		EnterStateComponents();
	}

	void P0_JumpForward::OnExit()
	{
		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_JumpForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}