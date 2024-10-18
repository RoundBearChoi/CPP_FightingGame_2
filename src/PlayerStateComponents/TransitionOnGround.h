#pragma once

#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
    class TransitionOnGround : public RB::States::StateComponentBase
    {
    public:
        TransitionOnGround(RB::States::iState* nextState);
		~TransitionOnGround() override {};
    
    public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
        void OnFixedUpdate() override;
    };
}
