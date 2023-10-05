#include "TriggerIdleOnAnimationEnd.h"

namespace RB::PlayerStateComponents
{
	void TriggerIdleOnAnimationEnd::OnEnter()
	{

	}

	void TriggerIdleOnAnimationEnd::OnFixedUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}

		RB::Players::iPlayer* player = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_state->GetStateMachineID());

		RB::PlayerStates::PlayerState* state = RB::PlayerStates::ActivePlayerStates::GetPlayerState(player->GetPlayerID());

		if (state == nullptr)
		{
			return;
		}

		RB::Sprites::SpriteEnum spriteEnum = state->GetSpriteEnum();

		RB::Render::iAnimationObj* aniObj = RB::Render::PLAYER_ANIMATION_CONTROLLER->GetAnimationObj(player->GetPlayerID(), spriteEnum);

		if (aniObj == nullptr)
		{
			return;
		}

		const RB::Render::AnimationSpecs& specs = aniObj->GetAnimationSpecs();

		size_t updates = state->GetCumulatedFixedUpdates();

		if (specs.mTotalSprites * (specs.mSkipFixedUpdates + 1) <= updates)
		{
			player->GetStateMachine()->QueueNextState(new RB::PlayerStates::P0_Idle());
		}
	}
}