#pragma once
#include <vector>
#include "iState.h"

namespace RB::States
{
	class StateComponentBase
	{
	public:
		StateComponentBase() = default;
		virtual ~StateComponentBase();

	public:
		virtual void SetState(iState* state);

	public:
		virtual void OnEnter();
		virtual void OnExit();
		virtual void OnUpdate();
		virtual void OnFixedUpdate();

		const virtual int& GetFixedUpdateOnCount() const;
		virtual bool ContainsState(unsigned int stateID);
		virtual void SetStateMachineID(unsigned int id);

	protected:
		iState* _state = nullptr;
		std::vector<iState*> _vecNextStates;
		int _fixedUpdateOnCount = -1; //ignore when -1
	};
}