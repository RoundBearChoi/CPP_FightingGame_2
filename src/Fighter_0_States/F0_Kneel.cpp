#include "F0_Kneel.h"

#include "F0_Lie_Down.h"

namespace RB::Fighter_0_States
{
	F0_Kneel::F0_Kneel()
	{
		_spriteType = Sprites::SPRITE_TYPE::fighter_0_kneel;
	}

    void F0_Kneel::OnEnter()
    {
        AddStateComponent(new PlayerStateComponents::TransitionOnAnimationEnd(new F0_Lie_Down()));

        EnterStateComponents();
    }

    void F0_Kneel::OnExit()
    {
        ExitStateComponents();
    }

    void F0_Kneel::OnUpdate()
    {
        UpdateStateComponents();
    }

    void F0_Kneel::OnFixedUpdate()
    {
        FixedUpdateStateComponents();
    }
}
