#include "P0_WalkForward.h"

namespace RB::PlayerStates::Aku
{
	void P0_WalkForward::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_walk;

		RB::Players::MoveSpecs m = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::PlayerStates::Aku::P0_JumpForwardUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::Aku::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingForward(m.mWalk_Forward_Speed, new RB::PlayerStates::Aku::P0_Idle(), new RB::PlayerStates::Aku::P0_WalkBack()));

		EnterStateComponents();
	}

	void P0_WalkForward::OnExit()
	{
		ExitStateComponents();
	}

	void P0_WalkForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_WalkForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
