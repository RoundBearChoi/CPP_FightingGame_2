#pragma once

#include <vector>

#include "BackgroundObj.h"

#include "../Render/RenderLayerType.h"

#include "../iBackgroundController.h"

namespace RB::Background
{
	class BackgroundController : public iBackgroundController
	{
	public:
		BackgroundController() = default;
		~BackgroundController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		std::vector<BackgroundObj*> _vecBackgroundObjs;
	};
}
