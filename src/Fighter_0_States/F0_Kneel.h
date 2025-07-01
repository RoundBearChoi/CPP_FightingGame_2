#pragma once

#include "../Players/PlayerState.h"

#include "../PlayerStateComponents/TransitionOnAnimationEnd.h"

namespace RB::Fighter_0_States
{
    class F0_Kneel : public Players::PlayerState
    {
    public:
		F0_Kneel(); 

    public:
        void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
    };
}
