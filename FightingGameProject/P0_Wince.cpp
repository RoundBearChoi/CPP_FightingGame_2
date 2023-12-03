#include "P0_Wince.h"

namespace RB::PlayerStates
{
	void P0_Wince::OnEnter()
	{
		ActivePlayerStates::AddPlayerState(this);

		StandardInit(RB::Sprites::SpriteEnum::fighter_0_wince);

		_ownerPlayer->SetWincingStatus(true);

		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(_ownerPlayer->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, false, 2)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, true, 2)); //forward, rest
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, true, 3)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, false, 4)); //way back, rest
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, false, 2)); // slightly back
		AddStateComponent(new RB::PlayerStateComponents::TriggerIdleOnFixedUpdateCount(10));

		EnterStateComponents();
	}

	void P0_Wince::OnExit()
	{
		_ownerPlayer->SetWincingStatus(false);

		ExitStateComponents();
		ActivePlayerStates::RemovePlayerState(this);
	}

	void P0_Wince::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Wince::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}