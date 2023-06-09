#include "P0_Dummy.h"

namespace RB::PlayerStates
{
	void P0_Dummy::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		//change spriteEnum to edit different sprites
		_spriteEnum = RB::Sprites::SpriteEnum::fighter_0_idle;

		_manualAnimationUpdater.OnEnter(_spriteEnum);
	}

	void P0_Dummy::OnExit()
	{
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Dummy::OnUpdate()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr ||
			RB::HBox::HURTBOX_DATA_CONTROLLER == nullptr)
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