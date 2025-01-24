#include "F0_JumpForward_0.h"

#include "F0_JumpForward_1.h"

namespace RB::Fighter_0_States
{
	void F0_JumpForward_0::OnEnter()
	{
		RB::Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_forward_0;

		RB::Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpForward_totalFrames / 2, moveSpecs.mJumpForward_verSpeedMultiplier));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpForward_totalFrames / 2, moveSpecs.mJumpForward_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::FIRST_HALF));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpForward_totalFrames / 2, new F0_JumpForward_1()));

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