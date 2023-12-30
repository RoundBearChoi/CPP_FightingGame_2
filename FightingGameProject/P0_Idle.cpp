#include "P0_Idle.h"

#include "DoNotFixDirectionDuringState.h"
#include "TransitionToJumpForward.h"
#include "TransitionToJumpUp.h"
#include "TransitionOnInput.h"
#include "TransitionToWalkForward.h"
#include "TransitionToWalkBack.h"

#include "P0_Crouch.h"
#include "P0_Jab.h"

namespace RB::PlayerStates::Aku
{
	void P0_Idle::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_idle;

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::PlayerStates::Aku::P0_JumpForwardUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::PlayerStates::Aku::P0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new P0_Jab(), RB::Input::PlayerInput::ATTACK_WEAK_PUNCH, true, false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkForward(new RB::PlayerStates::Aku::P0_WalkForward()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkBack(new RB::PlayerStates::Aku::P0_WalkBack()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new RB::PlayerStates::Aku::P0_Crouch(), RB::Input::PlayerInput::MOVE_DOWN, false, true));

		EnterStateComponents();
	}

	void P0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}