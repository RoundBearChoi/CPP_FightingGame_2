#include "F0_JumpForward_1.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	F0_JumpForward_1::F0_JumpForward_1()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_jump_forward_1;
	}

	void F0_JumpForward_1::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::MoveDownOnFall(20, 20.0f));
		AddStateComponent(new PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpForward_totalFrames / 2,  moveSpecs.mJumpForward_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::SECOND_HALF));
		AddStateComponent(new PlayerStateComponents::TransitionOnGround(new Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_JumpForward_1::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpForward_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpForward_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
