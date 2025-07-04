#include "F0_Crouch_Weak_Wince.h"
#include "F0_Crouch_Idle.h"

namespace RB::Fighter_0_States
{
	F0_Crouch_Weak_Wince::F0_Crouch_Weak_Wince()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_crouch_weak_wince;
	}

	void F0_Crouch_Weak_Wince::OnEnter()
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
		
		AddStateComponent(new PlayerStateComponents::TransitionOnFixedUpdateCount(10, new Fighter_0_States::F0_Crouch_Idle()));
		AddStateComponent(new PlayerStateComponents::TransitionOnDeath(10, new Fighter_0_States::F0_Kneel()));

		EnterStateComponents();
	}

	void F0_Crouch_Weak_Wince::OnExit()
	{
		ExitStateComponents();
	}

	void F0_Crouch_Weak_Wince::OnUpdate()
	{
		UpdateStateComponents();
	}

	void F0_Crouch_Weak_Wince::OnFixedUpdate()
	{
		FixedUpdateStateComponents();
	}
}
