#include "F0_Kneel.h"

#include "F0_Lie_Down.h"

namespace RB::Fighter_0_States
{
    void F0_Kneel::OnEnter()
    {
		_spriteType = Sprites::SpriteType::fighter_0_kneel;

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