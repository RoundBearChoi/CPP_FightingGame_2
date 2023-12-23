#include "P0_Wince.h"

namespace RB::PlayerStates::Aku
{
	void P0_Wince::OnEnter()
	{
		_spriteEnum = RB::Sprites::SpriteEnum::aku_wince;

		//GetPlayer()->SetWincingStatus(true);

		AddStateComponent(new RB::PlayerStateComponents::FixWincingStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::ToggleInitiallyFacingRight(GetPlayer()->OtherPlayerIsOnRightSide()));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, false, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, true, 4)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, false, 4)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, false, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, true, 2)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, true, 2)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, true, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, false, 8)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, false, 5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, false, 0));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(10, new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Wince::OnExit()
	{
		//GetPlayer()->SetWincingStatus(false);

		ExitStateComponents();
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