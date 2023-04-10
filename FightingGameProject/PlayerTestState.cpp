#include "PlayerTestState.h"
#include "Idle.h"

namespace RB::PlayerStates
{
	PlayerTestState::PlayerTestState()
	{

	}

	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnEnter()
	{
		//_skipFixedUpdates.SetSkipFrames(1);
		//_skipFixedUpdates.SetFunction(this, &PlayerTestState::Move);

		_triggerOnFixedUpdateCount.SetTargetFixedUpdate(1);
		_triggerOnFixedUpdateCount.SetFunction(this, &PlayerTestState::TransitionToIdle);
	}

	void PlayerTestState::OnFixedUpdate()
	{
		//_skipFixedUpdates.OnFixedUpdate();

		_triggerOnFixedUpdateCount.OnFixedUpdate();
	}

	void PlayerTestState::Move()
	{
		RB::Players::iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());
		
		player->Move(olc::vi2d{ 1, 1 });
	}

	void PlayerTestState::TransitionToIdle()
	{
		_stateMachine->QueueNextState(new RB::PlayerStates::Idle());
	}
}