#include "F0_JumpUp_0.h"

namespace RB::Fighter_0_States
{
	F0_JumpUp_0::F0_JumpUp_0()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_jump_up;
	}
	
	void F0_JumpUp_0::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpUp_totalFrames, moveSpecs.mJumpUp_speedMultiplier));
		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpUp_totalFrames, new F0_JumpUp_1()));

		EnterStateComponents();
	}

	void F0_JumpUp_0::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
