#include "F0_Weak_Wince_Mid.h"
#include "F0_Kneel.h"

namespace RB::Fighter_0_States
{
	F0_Weak_Wince_Mid::F0_Weak_Wince_Mid()
	{
		_spriteType = Sprites::SpriteType::fighter_0_weak_wince_mid;
	}

	void F0_Weak_Wince_Mid::OnEnter()
	{
		AddStateComponent(new PlayerStateComponents::SetWincingStatusOnEnter(true));
		AddStateComponent(new PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, 3)); //forward
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, -3)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, 1)); //forward
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 2)); //forward
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, 0));
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, -8)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, -5)); //back
		AddStateComponent(new PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, 0));
		
		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(10, new Fighter_0_States::F0_Idle()));
		AddStateComponent(new PlayerStateComponents::TransitionOnDeath(10, new Fighter_0_States::F0_Kneel()));

		EnterStateComponents();
	}

	void F0_Weak_Wince_Mid::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Weak_Wince_Mid::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Weak_Wince_Mid::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
