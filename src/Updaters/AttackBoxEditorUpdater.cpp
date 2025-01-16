#include "AttackBoxEditorUpdater.h"

namespace RB::Updaters
{
	AttackBoxEditorUpdater::AttackBoxEditorUpdater()
	{
		_settingsPath = "../resource/EditorSettings/AttackBoxSettings.editorSettings";
		_specsPath = "../resource/AttackBoxSpecs/";
		_boxType = RB::HBox::HBoxType::ATTACK_BOX;
		_pageTitle = "AttackBoxEditor";
	}
}