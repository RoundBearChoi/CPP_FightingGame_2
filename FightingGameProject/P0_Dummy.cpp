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
		//_getter_hurtBoxDataController.OnUpdate();

		//if (_getter_hurtBoxDataController.GetController() == nullptr)
		//{
		//	return;
		//}

		if (RB::Players::PlayerController::PTR == nullptr ||
			RB::HBox::HurtBoxDataController::PTR == nullptr)
		{
			return;
		}
		
		_ownerPlayer = RB::Players::PlayerController::PTR->GetPlayerOnStateMachineID(_stateMachineID);

		_manualAnimationUpdater.OnUpdate();
	}

	void P0_Dummy::OnFixedUpdate()
	{
		_manualAnimationUpdater.OnFixedUpdate();
	}
}