#pragma once

#include "iUpdaterObj.h"

#include "string"
#include "HBoxType.h"

namespace RB::Updaters
{
	class HBoxEditorUpdaterBase : public iUpdaterObj
	{
	public:
		HBoxEditorUpdaterBase() = default;
		~HBoxEditorUpdaterBase() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	protected:
		std::string _settingsPath = "";
		std::string _specsPath = "";
		RB::HBox::HBoxType _boxType = RB::HBox::HBoxType::NONE;
		std::string _pageTitle = "HBoxEditor";
	};
}
