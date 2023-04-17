#include "Player0_Start.h"
#include "P0_Idle.h"

namespace RB::Player0_States
{
	Player0_Start::Player0_Start()
	{

	}

	void Player0_Start::OnEnter()
	{
		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &Player0_Start::TransitionToIdle);
	}

	void Player0_Start::OnFixedUpdate()
	{
		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void Player0_Start::Move()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());
		
		player->Move(olc::vi2d{ 1, 1 });
	}

	void Player0_Start::TransitionToIdle()
	{
		_stateMachine->QueueNextState(new RB::Player0_States::P0_Idle());
	}
}