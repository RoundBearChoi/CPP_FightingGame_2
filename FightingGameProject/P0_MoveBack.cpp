#include "P0_MoveBack.h"

namespace RB::PlayerStates
{
	void P0_MoveBack::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::NONE);

		_ownerPlayer->FixDirDuringState(false);

		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack());

		EnterStateComponents();
	}

	void P0_MoveBack::OnExit()
	{
		_ownerPlayer->FixDirDuringState(true);

		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_MoveBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_MoveBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}