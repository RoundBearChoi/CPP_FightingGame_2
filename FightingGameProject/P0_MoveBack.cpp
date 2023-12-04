#include "P0_MoveBack.h"

namespace RB::PlayerStates
{
	void P0_MoveBack::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::NONE;
		//StandardInit(RB::Sprites::SpriteEnum::NONE);

		AddStateComponent(new RB::PlayerStateComponents::FixDirectionDuringState(false));
		AddStateComponent(new RB::PlayerStateComponents::TriggerJumpUp());
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack());

		EnterStateComponents();
	}

	void P0_MoveBack::OnExit()
	{
		ExitStateComponents();
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