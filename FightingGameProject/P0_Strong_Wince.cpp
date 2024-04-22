#include "P0_Strong_Wince.h"

#include "FixWincingStatusDuringState.h"
#include "MarkInitiallyFacingRight.h"
#include "MoveHorizontalOnFixedUpdateCount.h"
#include "TransitionOnFixedUpdateCount.h"

#include "P0_Idle.h"

namespace RB::PlayerStates::Aku
{
	void P0_Strong_Wince::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::aku_strong_wince;

		AddStateComponent(new RB::PlayerStateComponents::FixWincingStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());

		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, -5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 5)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, -7)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, 5)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, -7)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(10, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(11, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(12, -4)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(13, -8)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(14, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(15, -8)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(16, -8)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(17, -5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(18, -5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(19, -5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(20, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(21, -4)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(22, -4)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(23, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(24, 0));

		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(25, new RB::PlayerStates::Aku::P0_Idle()));

		EnterStateComponents();
	}

	void P0_Strong_Wince::OnExit()
	{
		ExitStateComponents();
	}

	void P0_Strong_Wince::OnUpdate()
	{
		UpdateStateComponents();
	}

	void P0_Strong_Wince::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}