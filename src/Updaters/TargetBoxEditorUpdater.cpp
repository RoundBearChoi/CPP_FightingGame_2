#include "TargetBoxEditorUpdater.h"

namespace RB::Updaters
{
	TargetBoxEditorUpdater::TargetBoxEditorUpdater()
	{
		_settingsPath = "../resource/EditorSettings/TargetBoxSettings.editorSettings";
		_specsPath = "../resource/TargetBoxSpecs/";
		_boxType = RB::HBox::HBoxType::TARGET_BOX;
		_pageTitle = "TargetBoxEditor";
	}
}