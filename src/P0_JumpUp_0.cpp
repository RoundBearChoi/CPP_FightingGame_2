#include "P0_JumpUp_0.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpUp_0::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_up;

		RB::Players::MoveSpecs moveSpecs = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(moveSpecs.mJumpUp_totalFrames, moveSpecs.mJumpUp_speedMultiplier, new P0_JumpUp_1()));

		EnterStateComponents();
	}

	void P0_JumpUp_0::OnExit()
	{
		ExitStateComponents();
	}

	void P0_JumpUp_0::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_JumpUp_0::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
