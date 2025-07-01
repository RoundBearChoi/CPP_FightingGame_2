#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	F0_Idle::F0_Idle()
	{
		_spriteType = Sprites::SpriteType::fighter_0_idle;
	}

	void F0_Idle::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new PlayerStateComponents::TransitionToJumpForward(new Fighter_0_States::F0_JumpForward_0(), false));
		AddStateComponent(new PlayerStateComponents::TransitionToJumpForward(new Fighter_0_States::F0_JumpBack_0(), true));
		AddStateComponent(new PlayerStateComponents::TransitionToJumpUp(new Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new PlayerStateComponents::TransitionOnInput(new F0_Strong_Kick(), Input::PlayerInput::ATTACK_STRONG_KICK, Input::InputType::ATTACK));
		AddStateComponent(new PlayerStateComponents::TransitionOnInput(new F0_Strong_Punch(), Input::PlayerInput::ATTACK_STRONG_PUNCH, Input::InputType::ATTACK));
		AddStateComponent(new PlayerStateComponents::TransitionOnInput(new F0_Jab(), Input::PlayerInput::ATTACK_WEAK_PUNCH, Input::InputType::ATTACK));
		AddStateComponent(new PlayerStateComponents::TransitionToWalkForward(new Fighter_0_States::F0_WalkForward()));
		AddStateComponent(new PlayerStateComponents::TransitionToWalkBack(new Fighter_0_States::F0_WalkBack()));
		AddStateComponent(new PlayerStateComponents::TransitionOnInput(new Fighter_0_States::F0_Crouch(), Input::PlayerInput::MOVE_DOWN, Input::InputType::MOVEMENT));

		EnterStateComponents();
	}

	void F0_Idle::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Idle::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Idle::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
