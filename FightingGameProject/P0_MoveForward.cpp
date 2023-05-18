#include "P0_MoveForward.h"

namespace RB::PlayerStates
{
	void P0_MoveForward::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);


		StandardInit(RB::Sprites::SpriteEnum::fighter_0_walk);

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward());

		EnterStateComponents();
	}

	void P0_MoveForward::OnExit()
	{
		ExitStateComponents();

		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_MoveForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_MoveForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}