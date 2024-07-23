#include "P0_WalkBack.h"

namespace RB::Fighter_0_States
{
	void P0_WalkBack::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::NONE;

		RB::Players::MoveSpecs m = RB::Players::iSpecsController::Get()->GetMoveSpecs(RB::Players::CharacterType::AKU);

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack(m.mWalk_Back_Speed, new RB::Fighter_0_States::F0_Idle(), new RB::Fighter_0_States::P0_WalkForward()));

		EnterStateComponents();
	}

	void P0_WalkBack::OnExit()
	{
		ExitStateComponents();
	}

	void P0_WalkBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_WalkBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
