#include "P0_Idle.h"

namespace RB::PlayerStates
{
	void P0_Idle::OnEnter()
	{
		//ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_idle);

		//_ownerPlayer->FixDirDuringState(false);

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::TriggerJab(new P0_Jab()));
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		//_ownerPlayer->FixDirDuringState(true);

		ExitStateComponents();
		//ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}