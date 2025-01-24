#pragma once

#include "../Players/PlayerState.h"

namespace RB::Fighter_0_States
{
    class F0_Lie_Down : public Players::PlayerState
    {
    public:
		F0_Lie_Down() = default;

    public:
        void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
    };
}