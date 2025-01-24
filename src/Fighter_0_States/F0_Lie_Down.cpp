#include "F0_Lie_Down.h"

namespace RB::Fighter_0_States
{
    void F0_Lie_Down::OnEnter()
    {
		_spriteType = Sprites::SpriteType::fighter_0_lie_down;

        EnterStateComponents();
    }

    void F0_Lie_Down::OnExit()
    {
        ExitStateComponents();
    }

    void F0_Lie_Down::OnUpdate()
    {
        UpdateStateComponents();
    }

    void F0_Lie_Down::OnFixedUpdate()
    {
        FixedUpdateStateComponents();
    }
}