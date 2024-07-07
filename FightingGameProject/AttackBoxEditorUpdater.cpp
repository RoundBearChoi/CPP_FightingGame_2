#include "AttackBoxEditorUpdater.h"

namespace RB::Updaters
{
	AttackBoxEditorUpdater::AttackBoxEditorUpdater()
	{
		_settingsPath = "EditorSettings/AttackBoxSettings.editorSettings";
		_specsPath = "AttackBoxSpecs/";
		_boxType = RB::HBox::HBoxType::ATTACK_BOX;
		_pageTitle = "AttackBoxEditor";
	}
}
