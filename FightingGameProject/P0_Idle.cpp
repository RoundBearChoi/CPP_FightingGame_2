#include "P0_Idle.h"

namespace RB::PlayerStates
{
	void P0_Idle::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		_getter_PlayerController.FindController();
		_ownerPlayer = _getter_PlayerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);

		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveForward());
		AddStateComponent(new RB::PlayerStateComponents::TriggerMoveBack());

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();

		ActivePlayerStates::RemovePlayerState(this);
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