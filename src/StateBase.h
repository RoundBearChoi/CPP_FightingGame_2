#pragma once

#include <iostream>
#include <vector>

#include "StateComponentBase.h"

namespace RB::States
{
	class StateBase : public iState
	{
	public:
		static unsigned int stateCreationCount;

	public:
		StateBase();
		~StateBase() override;

		virtual unsigned int GetStateID() override;
		virtual void SetStateMachineID(unsigned int id) override;
		virtual unsigned int GetStateMachineID() override;
		virtual void SetStateMachineIDs_Recursively() override;
		virtual void SetIsTransitioning(bool status) override;
		virtual bool IsTransitioning() override;
		virtual void AddCumulatedFixedUpdate() override;
		virtual unsigned int GetCumulatedFixedUpdates() override;
		virtual bool ContainsState_Recursive(unsigned int stateID) override;

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
		virtual void ErasePreviousStates() override {}

	protected:
		unsigned int _stateCreationID = 0;
		unsigned int _stateMachineID = 0;
		unsigned int _cumulatedFixedUpdates = 0;
		bool _isTransitioning = false;
		std::vector<StateComponentBase*> _vecStateComponents;
	};
}
