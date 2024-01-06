#include "P0_JumpUp_0.h"

#include "MarkInitiallyFacingRight.h"
#include "MoveUpOnJump.h"

#include "P0_JumpUp_1.h"

#include "iSpecsController.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpUp_0::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteType::aku_jump_up_0;

		RB::Players::Specs::MoveSpecs moveSpecs = RB::Players::Specs::iSpecsController::instance->GetMoveSpecs(RB::Players::CharacterType::AKU);

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