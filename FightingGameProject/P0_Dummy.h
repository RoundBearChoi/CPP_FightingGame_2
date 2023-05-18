#pragma once
#include "StateBase.h"
#include "ManualAnimationUpdater.h"
#include "ManualTransitioner.h"
#include "SpriteEnum.h"
#include "ControllerFinder.h"
#include "HurtBoxDataController.h"

namespace RB::P0_States
{
	class P0_Dummy : public RB::States::StateBase
	{
	public:
		P0_Dummy() = default;
		~P0_Dummy() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;

	private:
		//RB::HurtBox::HurtBoxDataController* _hurtBoxDataController = nullptr;
		RB::Controllers::ControllerFinder<RB::HurtBox::HurtBoxDataController> _finder_HurtBoxDataController;
	};
}