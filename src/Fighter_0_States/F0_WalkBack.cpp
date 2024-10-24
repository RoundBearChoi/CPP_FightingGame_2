#include "F0_WalkBack.h"

namespace RB::Fighter_0_States
{
	void F0_WalkBack::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::NONE;

		RB::Players::MoveSpecs m = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::Fighter_0_States::F0_JumpBack_0(), true));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack(m.mWalk_Back_Speed, new RB::Fighter_0_States::F0_Idle(), new RB::Fighter_0_States::F0_WalkForward()));

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
