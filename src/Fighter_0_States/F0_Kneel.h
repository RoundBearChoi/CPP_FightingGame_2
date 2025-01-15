#pragma once

#include "../Players/PlayerState.h"

namespace RB::Fighter_0_States
{
    class F0_Kneel : public RB::Players::PlayerState
    {
    public:
		F0_Kneel() = default;

    public:
        void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
    };
}