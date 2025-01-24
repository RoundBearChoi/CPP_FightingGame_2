#include "F0_JumpBack_1.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	void F0_JumpBack_1::OnEnter()
	{
		RB::Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = RB::Sprites::SpriteType::fighter_0_jump_back_1;

		RB::Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::MoveDownOnFall(20, 20.0f));
		AddStateComponent(new RB::PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpBack_totalFrames / 2,  moveSpecs.mJumpBack_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::SECOND_HALF));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnGround(new RB::Fighter_0_States::F0_Idle()));

		EnterStateComponents();
	}

	void F0_JumpBack_1::OnExit()
	{
		ExitStateComponents();
	}

	void F0_JumpBack_1::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_JumpBack_1::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}