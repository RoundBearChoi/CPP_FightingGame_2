#include "F0_WalkBack.h"

namespace RB::Fighter_0_States
{
	F0_WalkBack::F0_WalkBack()
	{
		_spriteType = Sprites::SPRITE_TYPE::NONE;
	}

	void F0_WalkBack::OnEnter()
	{
		Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		Players::MoveSpecs m = specsController->GetMoveSpecs(Players::CharacterType::AKU);

		AddStateComponent(new PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new PlayerStateComponents::TransitionToJumpForward(new Fighter_0_States::F0_JumpBack_0(), true));
		AddStateComponent(new PlayerStateComponents::TransitionToJumpUp(new Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new PlayerStateComponents::WhileMovingBack(m.mWalk_Back_Speed, new Fighter_0_States::F0_Idle(), new Fighter_0_States::F0_WalkForward()));

		EnterStateComponents();
	}

	void F0_WalkBack::OnExit()
	{
		ExitStateComponents();
	}

	void F0_WalkBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_WalkBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
