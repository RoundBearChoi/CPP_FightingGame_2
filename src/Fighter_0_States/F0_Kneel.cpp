#include "F0_Kneel.h"

namespace RB::Fighter_0_States
{
    void F0_Kneel::OnEnter()
    {
		_spriteType = RB::Sprites::SpriteType::fighter_0_kneel;

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