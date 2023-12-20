#include "P0_JumpForwardUp_0.h"

namespace RB::PlayerStates::Aku
{
	void P0_JumpForwardUp_0::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_jump_forward_up_0;

		RB::Players::Specs::MoveSpecs moveSpecs = RB::Players::Specs::iSpecsController::instance->GetMoveSpecs(RB::Players::CharacterType::PLAYER_0);

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveUpOnJump(20, 22.0f, new P0_JumpForwardUp_1));
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