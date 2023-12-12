#pragma once
#include <vector>
#include <cstdint>
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

		const virtual int32_t& GetFixedUpdateOnCount() const;
		const virtual int32_t& GetUpdateOnCount() const;

	protected:
		iState* _state = nullptr;
		//iState* _nextState = nullptr;
		std::vector<iState*> _vecNextStates;
		int32_t _fixedUpdateOnCount = -1;
		int32_t _updateOnCount = -1;
	};
}