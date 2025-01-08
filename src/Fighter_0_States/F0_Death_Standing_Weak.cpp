#include "F0_Death_Standing_Weak.h"

namespace RB::Fighter_0_States
{
    void F0_Death_Standing_Weak::OnEnter()
    {
		_spriteType = RB::Sprites::SpriteType::fighter_0_death_standing_weak;

        EnterStateComponents();
    }

    void F0_Death_Standing_Weak::OnExit()
    {
        ExitStateComponents();
    }

    void F0_Death_Standing_Weak::OnUpdate()
    {
        UpdateStateComponents();
    }

    void F0_Death_Standing_Weak::OnFixedUpdate()
    {
        FixedUpdateStateComponents();
    }
}