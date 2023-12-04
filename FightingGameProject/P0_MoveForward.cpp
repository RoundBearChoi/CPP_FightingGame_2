#include "P0_MoveForward.h"

namespace RB::PlayerStates
{
	void P0_MoveForward::OnEnter()
	{
		//ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_walk);

		//_ownerPlayer->FixDirDuringState(false);

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward());

		EnterStateComponents();
	}

	void P0_MoveForward::OnExit()
	{
		//_ownerPlayer->FixDirDuringState(true);

		ExitStateComponents();
		//ActivePlayerStates::RemovePlayerState(this);
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