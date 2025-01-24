#include "F0_JumpUp_0.h"

namespace RB::Fighter_0_States
{
	void F0_JumpUp_0::OnEnter()
	{
		RB::Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_up;

		RB::Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpUp_totalFrames, moveSpecs.mJumpUp_speedMultiplier));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpUp_totalFrames, new F0_JumpUp_1()));

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