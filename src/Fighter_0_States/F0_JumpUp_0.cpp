#include "F0_JumpUp_0.h"

namespace RB::Fighter_0_States
{
	void F0_JumpUp_0::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = Sprites::SpriteType::fighter_0_jump_up;

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