#include "F0_WalkForward.h"

namespace RB::Fighter_0_States
{
	void F0_WalkForward::OnEnter()
	{
		RB::Players::iSpecsController* specsController = GET_SPECS_CONTROLLER;

		_spriteType = RB::Sprites::SpriteType::fighter_0_walk;

		RB::Players::MoveSpecs m = specsController->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::Fighter_0_States::F0_JumpForward_0(), false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward(m.mWalk_Forward_Speed, new RB::Fighter_0_States::F0_Idle(), new RB::Fighter_0_States::F0_WalkBack()));

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