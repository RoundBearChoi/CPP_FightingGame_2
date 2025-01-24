#include "F0_JumpForward_1.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	void F0_JumpForward_1::OnEnter()
	{
		RB::Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_forward_1;

		RB::Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 20.0f));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpForward_totalFrames / 2,  moveSpecs.mJumpForward_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::SECOND_HALF));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnGround(new RB::Fighter_0_States::F0_Idle()));

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