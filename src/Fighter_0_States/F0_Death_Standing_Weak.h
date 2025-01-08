#pragma once

#include "../Players/PlayerState.h"

namespace RB::Fighter_0_States
{
    class F0_Death_Standing_Weak : public RB::Players::PlayerState
    {
    public:
		F0_Death_Standing_Weak() = default;

    public:
        void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
    };
}