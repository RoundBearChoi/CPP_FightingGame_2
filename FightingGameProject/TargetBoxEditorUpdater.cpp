#include "TargetBoxEditorUpdater.h"

namespace RB::Updaters
{
	TargetBoxEditorUpdater::TargetBoxEditorUpdater()
	{
		_settingsPath = "EditorSettings/TargetBoxSettings.editorSettings";
		_specsPath = "TargetBoxSpecs/";
		_boxType = RB::HBox::HBoxType::TARGET_BOX;
	}
}
