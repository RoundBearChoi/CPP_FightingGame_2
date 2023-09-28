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

	private:
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
	};

	extern HBoxEditControllerBase* HURTBOX_EDIT_CONTROLLER;
}