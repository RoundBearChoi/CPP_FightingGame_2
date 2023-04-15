#include "MoveForward.h"

namespace RB::PlayerStates
{
	MoveForward::MoveForward()
	{

	}

	void MoveForward::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::KeepMovingForward());

		EnterStateComponents();
	}

	void MoveForward::OnExit()
	{
		ExitStateComponents();
	}

	void MoveForward::OnUpdate()
	{
		UpdateStateComponents();
	}

	void MoveForward::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}