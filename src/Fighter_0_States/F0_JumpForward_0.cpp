#include "F0_JumpForward_0.h"
#include "F0_JumpForward_1.h"

namespace RB::Fighter_0_States
{
	void F0_JumpForward_0::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_forward_0;

		RB::Players::MoveSpecs moveSpecs = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpForward_totalFrames, moveSpecs.mJumpForward_horSpeedMultiplier));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump_0(20, 7.0f));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpForward_totalFrames, new F0_JumpForward_1()));

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
