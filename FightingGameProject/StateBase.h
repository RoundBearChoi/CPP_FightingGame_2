#pragma once
#include <iostream>
#include <vector>
#include "iState.h"
#include "iStateMachine.h"
#include "StateComponentBase.h"

namespace RB::States
{
	class StateBase : public iState
	{
	public:
		StateBase();
		~StateBase() override;

		virtual void SetStateMachine(iStateMachine* stateMachine) override;
		virtual iStateMachine* GetStateMachine() override;
		virtual void QueueNextState(iState* nextState) override;
		virtual void AddCumulatedFixedUpdate() override;
		virtual size_t GetCumulatedFixedUpdates() override;
		virtual RB::Sprites::SpriteID GetSpriteID() override;

	public:
		virtual void AddStateComponent(StateComponentBase* stateComponent);
		virtual void EnterStateComponents();
		virtual void ExitStateComponents();
		virtual void UpdateStateComponents();
		virtual void FixedUpdateStateComponents();

	public:
		virtual void OnEnter() override {}
		virtual void OnExit() override {}
		virtual void OnUpdate() override {}
		virtual void OnFixedUpdate() override {}

	protected:
		iStateMachine* _stateMachine = nullptr;
		size_t _cumulatedFixedUpdates = 0;
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		std::vector<StateComponentBase*> _vecStateComponents;
	};
}