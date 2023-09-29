#pragma once

#include "HBoxEditControllerBase.h"

namespace RB::HBox
{
	class HBoxEditController : public HBoxEditControllerBase
	{
	public:
		HBoxEditController(RB::HBox::HBoxType boxType);
		~HBoxEditController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};

	extern HBoxEditControllerBase* HBOX_EDIT_CONTROLLER;
}