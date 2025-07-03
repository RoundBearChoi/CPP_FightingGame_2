#include "AttackBoxEditorUpdater.h"

namespace RB::Updaters
{
	AttackBoxEditorUpdater::AttackBoxEditorUpdater()
	{
		_updaterType = UPDATER_TYPE::ATTACK_BOX_EDITOR_UPDATER;

		_settingsPath = "../resource/EditorSettings/AttackBoxSettings.editorSettings";
		_specsPath = "../resource/AttackBoxSpecs/";
		_boxType = HBox::HBoxType::ATTACK_BOX;
		_pageTitle = "AttackBoxEditor";
	}
}
