#include "F0_JumpForward_0.h"

#include "F0_JumpForward_1.h"

namespace RB::Fighter_0_States
{
	F0_JumpForward_0::F0_JumpForward_0()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_jump_forward_0;
	}
	
	void F0_JumpForward_0::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpForward_totalFrames / 2, moveSpecs.mJumpForward_verSpeedMultiplier));
		AddStateComponent(new PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpForward_totalFrames / 2, moveSpecs.mJumpForward_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::FIRST_HALF));
		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpForward_totalFrames / 2, new F0_JumpForward_1()));

		EnterStateComponents();
	}

	void F0_JumpForward_0::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpForward_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpForward_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
