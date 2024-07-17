#pragma once
#include "iUpdaterObj.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public iUpdaterObj
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();
	};
}
