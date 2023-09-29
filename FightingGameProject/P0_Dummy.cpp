#include "P0_Dummy.h"

namespace RB::PlayerStates
{
	P0_Dummy::P0_Dummy(Sprites::SpriteEnum startingSpriteEnum)
	{
		_spriteEnum = startingSpriteEnum;
	}

	void P0_Dummy::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnExit()
	{
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Dummy::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return;
		}
		
		_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}