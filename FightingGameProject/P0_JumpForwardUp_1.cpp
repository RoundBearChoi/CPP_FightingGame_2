#include "P0_JumpForwardUp_1.h"

namespace RB::PlayerStates
{
	void P0_JumpForwardUp_1::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_1);

		//AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 20.0f));

		EnterStateComponents();
	}

	void P0_JumpForwardUp_1::OnExit()
	{
		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_JumpForwardUp_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpForwardUp_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}