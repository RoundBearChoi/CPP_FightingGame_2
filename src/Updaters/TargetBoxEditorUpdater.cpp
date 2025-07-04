#include "TargetBoxEditorUpdater.h"

namespace RB::Updaters
{
	TargetBoxEditorUpdater::TargetBoxEditorUpdater()
	{
		_updaterType = UPDATER_TYPE::TARGET_BOX_EDITOR_UPDATER;

		_boxType = HBox::HBoxType::TARGET_BOX;
		_pageTitle = "TargetBoxEditor";
	}
}
