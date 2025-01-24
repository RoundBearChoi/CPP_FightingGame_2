#include "F0_JumpBack_0.h"

#include "F0_JumpBack_1.h"

namespace RB::Fighter_0_States
{
	void F0_JumpBack_0::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = Sprites::SpriteType::fighter_0_jump_back_0;

		Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpBack_totalFrames / 2, moveSpecs.mJumpBack_verSpeedMultiplier));
		AddStateComponent(new PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpBack_totalFrames / 2, moveSpecs.mJumpBack_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::FIRST_HALF));
		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpBack_totalFrames / 2, new F0_JumpBack_1()));

		EnterStateComponents();
	}

	void F0_JumpBack_0::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpBack_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpBack_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}