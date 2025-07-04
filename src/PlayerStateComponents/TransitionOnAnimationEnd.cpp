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
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = playerController->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(player->GetPLAYER_TYPE());

		if (state == nullptr)
		{
			return;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(player->GetPLAYER_TYPE(), spriteType);

		if (aniObj == nullptr)
		{
			return;
		}

		const Render::AnimationSpecs& specs = aniObj->GetAnimationSpecs();

		unsigned int updates = state->GetCumulatedFixedUpdates();

		if ((specs.mTotalSprites /* - 1*/) * specs.mSkipFixedUpdates <= updates)
		{
			player->GetStateMachine()->QueueNextState(_vecNextStates[0]);
		}
	}
}
