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

		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, 3)); //forward
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, -3)); //back
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, 1)); //forward
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 2)); //forward
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, 0));
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, -8)); //back
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, -5)); //back
		//AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, 0));

		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(21, new RB::PlayerStates::Aku::P0_Idle()));

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