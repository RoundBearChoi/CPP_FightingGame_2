#include "F0_Idle.h"

namespace RB::Fighter_0_States
{
	void F0_Idle::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_idle;

		AddStateComponent(new RB::PlayerStateComponents::DoNotFixDirectionDuringState());
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::Fighter_0_States::F0_JumpForward_0(), false));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpForward(new RB::Fighter_0_States::F0_JumpBack_0(), true));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToJumpUp(new RB::Fighter_0_States::F0_JumpUp_0()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new F0_Strong_Kick(), RB::Input::PlayerInput::ATTACK_STRONG_KICK, RB::Input::InputType::ATTACK));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new F0_Strong_Punch(), RB::Input::PlayerInput::ATTACK_STRONG_PUNCH, RB::Input::InputType::ATTACK));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new F0_Jab(), RB::Input::PlayerInput::ATTACK_WEAK_PUNCH, RB::Input::InputType::ATTACK));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkForward(new RB::Fighter_0_States::F0_WalkForward()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionToWalkBack(new RB::Fighter_0_States::F0_WalkBack()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnInput(new RB::Fighter_0_States::F0_Crouch(), RB::Input::PlayerInput::MOVE_DOWN, RB::Input::InputType::MOVEMENT));

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
