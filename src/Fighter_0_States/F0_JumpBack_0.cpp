#include "F0_JumpBack_0.h"

//#include "F0_JumpForward_1.h"

namespace RB::Fighter_0_States
{
	void F0_JumpBack_0::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_back_0;

		RB::Players::MoveSpecs moveSpecs = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpBack_totalFrames / 2, moveSpecs.mJumpBack_verSpeedMultiplier));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpBack_totalFrames / 2, moveSpecs.mJumpBack_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::FIRST_HALF));
		//AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(moveSpecs.mJumpBack_totalFrames / 2, new F0_JumpForward_1()));

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
