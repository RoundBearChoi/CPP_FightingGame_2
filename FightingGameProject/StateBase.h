#pragma once
#include <iostream>
#include <vector>
#include "iState.h"
#include "iStateMachine.h"
#include "GameplayControllers.h"
#include "StateComponentBase.h"

namespace RB::States
{
	class StateBase : public iState
	{
	public:
		StateBase() = default;
		~StateBase() override;

		virtual void SetStateMachine(iStateMachine* stateMachine);
		virtual iStateMachine* GetStateMachine();
		virtual void QueueNextState(iState* nextState);
		virtual void AddCumulatedFixedUpdate();
		virtual unsigned int GetCumulatedFixedUpdates();
		virtual RB::Players::iPlayer* GetOwnerPlayer();
		virtual RB::Sprites::SpriteID GetSpriteID();

	public:
		virtual void AddStateComponent(StateComponentBase* stateComponent);
		virtual void EnterStateComponents();
		virtual void ExitStateComponents();
		virtual void UpdateStateComponents();
		virtual void FixedUpdateStateComponents();

	public:
		virtual void OnEnter() {}
		virtual void OnExit() {}
		virtual void OnUpdate() {}
		virtual void OnFixedUpdate() {}

	protected:
		iStateMachine* _stateMachine = nullptr;
		unsigned int _cumulatedFixedUpdates = 0;
		RB::Sprites::SpriteID _spriteID = RB::Sprites::SpriteID::NONE;
		std::vector<StateComponentBase*> _vecStateComponents;
	};
}