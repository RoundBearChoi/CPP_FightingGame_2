#pragma once

#include "UpdaterBase.h"

namespace RB::Updaters
{
	class PlayerBoxEditorUpdater : public UpdaterBase
	{
	public:
		PlayerBoxEditorUpdater() = default;
		~PlayerBoxEditorUpdater() override;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}