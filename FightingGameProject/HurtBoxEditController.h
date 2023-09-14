#pragma once

#include "HBoxEditControllerBase.h"

namespace RB::HBox
{
	class HurtBoxEditController : public HBoxEditControllerBase
	{
	public:
		HurtBoxEditController();
		~HurtBoxEditController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};

	extern HBoxEditControllerBase* HURTBOX_EDIT_CONTROLLER;
}