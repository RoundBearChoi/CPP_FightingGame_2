#include "PlayerBoxEditorUpdater.h"

#include "ControllerBase.h"

namespace RB::Updaters
{
	PlayerBoxEditorUpdater::~PlayerBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::OnEnd();
	}
	void PlayerBoxEditorUpdater::Init()
	{

	}

	void PlayerBoxEditorUpdater::OnUpdate()
	{
		RB::Controllers::ControllerBase::UpdateAll();
	}

	void PlayerBoxEditorUpdater::OnFixedUpdate()
	{
		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}