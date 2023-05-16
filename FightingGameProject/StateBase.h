#pragma once
#include <iostream>
#include <vector>
#include "iState.h"
#include "StateComponentBase.h"

namespace RB::States
{
	class StateBase : public iState
	{
	public:
		StateBase() = default;
		~StateBase() override;

		virtual void SetStateMachineID(size_t id) override;
		virtual size_t GetStateMachineID() override;
		virtual void SetTransitionStatus(bool status) override;
		virtual bool IsTransitioning() override;
		virtual void AddCumulatedFixedUpdate() override;
		virtual size_t GetCumulatedFixedUpdates() override;
		virtual RB::Sprites::SpriteEnum GetSpriteEnum() override;

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
		size_t _stateMachineID = 0;
		size_t _cumulatedFixedUpdates = 0;
		bool _isTransitioning = false;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<StateComponentBase*> _vecStateComponents;
	};
}