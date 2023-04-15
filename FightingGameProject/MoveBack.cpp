#include "MoveBack.h"

namespace RB::PlayerStates
{
	MoveBack::MoveBack()
	{

	}

	void MoveBack::OnEnter()
	{
		AddStateComponent(new RB::PlayerStateComponents::WhileMovingBack());

		EnterStateComponents();
	}

	void MoveBack::OnExit()
	{
		ExitStateComponents();
	}

	void MoveBack::OnUpdate()
	{
		UpdateStateComponents();
	}

	void MoveBack::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}