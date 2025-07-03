#pragma once

#include <string>

#include "UpdaterBase.h"

#include "../HBox/HBoxType.h"

namespace RB::Updaters
{
	class HBoxEditorUpdaterBase : public UpdaterBase
	{
	public:
		HBoxEditorUpdaterBase();
		~HBoxEditorUpdaterBase() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	protected:
		std::string _specsPath = "";
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
		std::string _pageTitle = "HBoxEditor";
	};
}
