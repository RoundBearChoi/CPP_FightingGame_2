#include "TransitionOnAnimationEnd.h"

namespace RB::PlayerStateComponents
{
	TransitionOnAnimationEnd::TransitionOnAnimationEnd(RB::States::iState* nextState)
	{
		_vecNextStates.push_back(nextState);
	}

	void TransitionOnAnimationEnd::OnEnter()
	{

	}

	void TransitionOnAnimationEnd::OnFixedUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		RB::Render::iAnimationObj* aniObj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(player->GetPlayerID(), spriteType);

		if (aniObj == nullptr)
		{
			return;
		}

		const RB::Render::AnimationSpecs& specs = aniObj->GetAnimationSpecs();

		unsigned int updates = state->GetCumulatedFixedUpdates();

		if ((specs.mTotalSprites /* - 1*/) * specs.mSkipFixedUpdates <= updates)
		{
			player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
		}
	}
}
