#include "TransitionOnGround.h"

namespace RB::PlayerStateComponents
{
    TransitionOnGround::TransitionOnGround(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

    void TransitionOnGround::OnEnter()
    {

    }

    void TransitionOnGround::OnExit()
    {

    }

    void TransitionOnGround::OnUpdate()
    {

    }

    void TransitionOnGround::OnFixedUpdate()
    {
        RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

        if (player == nullptr)
        {
            return;
        }

        float y = player->GetPosition().y;

        if (y >= -0.001)
        {
            player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
        }
    }
}
