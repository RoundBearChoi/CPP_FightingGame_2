#include "F0_Strong_Wince_Mid.h"

namespace RB::Fighter_0_States
{
	F0_Strong_Wince_Mid::F0_Strong_Wince_Mid()
	{
		_spriteType = Sprites::SpriteType::fighter_0_strong_wince_mid;
	}

	void F0_Strong_Wince_Mid::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::SetWincingStatusOnEnter(true));
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());

		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, -5)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, 0));
		//AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 0));
		//AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, 0));
		//AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 5)); //forward
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, -7)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, 5)); //forward
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, -7)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(10, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(11, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(12, -4)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(13, -8)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(14, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(15, -8)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(16, -8)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(17, -5)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(18, -5)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(19, -5)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(20, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(21, -4)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(22, -4)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(23, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(24, 0));

		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(25, new Fighter_0_States::F0_Idle()));
		AddStateComponent(new PlayerStateComponents::TransitionOnDeath(25, new Fighter_0_States::F0_Kneel()));

		EnterStateComponents();
	}

	void F0_Strong_Wince_Mid::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Strong_Wince_Mid::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Strong_Wince_Mid::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
