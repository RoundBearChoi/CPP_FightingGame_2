#include "F0_Lie_Down.h"

namespace RB::Fighter_0_States
{
	F0_Lie_Down::F0_Lie_Down()
	{
		_spriteType = Sprites::SpriteType::fighter_0_lie_down;
	}

    void F0_Lie_Down::OnEnter()
    {
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
