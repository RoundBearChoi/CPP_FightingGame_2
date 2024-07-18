#include "P0_JumpForwardUp_0.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpForwardUp_0::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_forward_0;

		RB::Players::Specs::MoveSpecs moveSpecs = RB::Players::Specs::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpUp_Forward_totalFrames, moveSpecs.mJumpUp_Forward_speedMultiplier, new P0_JumpForwardUp_1));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump_0(20, 7.0f));

		EnterStateComponents();
	}

	void P0_JumpForwardUp_0::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpForwardUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpForwardUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
