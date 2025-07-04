#include "F0_WalkForward.h"

namespace RB::Fighter_0_States
{
	F0_WalkForward::F0_WalkForward()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_walk;
	}

	void F0_WalkForward::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs m = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new PlayerStateComponents::TransitionToJumpForward(new Fighter_0_States::F0_JumpForward_0(), false));
		AddStateComponent(new PlayerStateComponents::TransitionToJumpUp(new Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new PlayerStateComponents::WhileMovingForward(m.mWalk_Forward_Speed, new Fighter_0_States::F0_Idle(), new Fighter_0_States::F0_WalkBack()));

		EnterStateComponents();
	}

	void F0_WalkForward::OnExit()
	{
		ExitStateComponents();
	}

	void F0_WalkForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_WalkForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
