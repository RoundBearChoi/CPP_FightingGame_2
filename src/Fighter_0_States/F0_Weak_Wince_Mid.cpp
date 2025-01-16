#include "F0_Weak_Wince_Mid.h"
#include "F0_Kneel.h"

namespace RB::Fighter_0_States
{
	void F0_Weak_Wince_Mid::OnEnter()
	{
		_spriteType = RB::Sprites::SpriteType::fighter_0_weak_wince_mid;

		AddStateComponent(new RB::PlayerStateComponents::FixWincingStatusDuringState(true));
		AddStateComponent(new RB::PlayerStateComponents::MarkInitiallyFacingRight());
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(0, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(1, 3)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(2, -3)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(3, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(4, 1)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(5, 2)); //forward
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(6, 0));
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(7, -8)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(8, -5)); //back
		AddStateComponent(new RB::PlayerStateComponents::MoveHorizontalOnFixedUpdateCount(9, 0));
		
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnFixedUpdateCount(10, new RB::Fighter_0_States::F0_Idle()));
		AddStateComponent(new RB::PlayerStateComponents::TransitionOnDeath(10, new RB::Fighter_0_States::F0_Kneel()));

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