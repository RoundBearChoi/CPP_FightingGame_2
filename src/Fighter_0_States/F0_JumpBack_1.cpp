#include "F0_JumpBack_1.h"

#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	F0_JumpBack_1::F0_JumpBack_1()
	{
		_spriteType = Sprites::SpriteType::fighter_0_jump_back_1;
	}
	
	void F0_JumpBack_1::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs moveSpecs = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::MoveDownOnFall(20, 20.0f));
		AddStateComponent(new PlayerStateComponents::MoveForwardOnJump(moveSpecs.mJumpBack_totalFrames / 2,  moveSpecs.mJumpBack_horSpeedMultiplier, PlayerStateComponents::MoveForwardOnJumpType::SECOND_HALF));
		AddStateComponent(new PlayerStateComponents::TransitionOnGround(new Fighter_0_States::F0_Idle()));

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
