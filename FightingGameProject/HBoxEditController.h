#pragma once

#include "HBoxEditControllerBase.h"

namespace RB::HBox
{
	class HBoxEditController : public HBoxEditControllerBase
	{
	public:
		HBoxEditController();
		~HBoxEditController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};

	extern HBoxEditControllerBase* HURTBOX_EDIT_CONTROLLER;
}